type Maze = [String]

sample1space :: Maze
sample1space = ["*********",
                "* *   * *",
                "* * * * *",
                "* * * * *",
                "*   *   *",
                "******* *",
                "        *",
                "*********"]

-- Výpis labyrintu
printMaze :: Maze -> IO ()
printMaze x = putStr (concatMap (++ "\n") x)

-- Čtení z labyrintu
getFromMaze :: Maze -> (Int, Int) -> Char
getFromMaze maze (row, col) = (maze !! row) !! col

replaceAt :: [a] -> Int -> a -> [a]
replaceAt xs i x = take i xs ++ [x] ++ drop (i + 1) xs

putIntoMaze :: Maze -> [(Int, Int, Char)] -> Maze
putIntoMaze maze [] = maze
putIntoMaze maze ((a, b, c) : xs) =
  let rows_before = take a maze
      row_current = (maze !! max 0 (length rows_before))
      char_before = take b row_current
      char_after = drop (length char_before +1) row_current
      row_after = drop (length rows_before +1) maze
      in putIntoMaze (rows_before ++ [char_before ++ [c] ++ char_after] ++ row_after) xs

-- BFS pro nalezení nejkratší cesty
getPath :: Maze -> (Int, Int) -> (Int, Int) -> Maybe [(Int, Int)]
getPath maze start end = bfs [(start, [])] []
  where
    bfs [] _ = Nothing
    bfs ((pos, path):queue) visited
      | pos == end = Just (reverse (pos:path))
      | pos `elem` visited = bfs queue visited
      | otherwise =
          let neighbors = filter validMove (adjacent pos)
              newQueue = queue ++ map (\n -> (n, pos:path)) neighbors
          in bfs newQueue (pos : visited)

    validMove (r, c) =
      r >= 0 && r < length maze && c >= 0 && c < length (head maze) &&
      getFromMaze maze (r, c) == ' ' -- volné pole

    adjacent (r, c) = [(r + dr, c + dc) | (dr, dc) <- [(-1, 0), (1, 0), (0, -1), (0, 1)]]

-- Funkce pro vytvoření cesty v bludišti
makePath :: Maze -> (Int, Int) -> (Int, Int) -> Maze
makePath maze start end =
  case getPath maze start end of
    Nothing -> maze -- Pokud cesta neexistuje, vrací původní bludiště
    Just path -> 
      let updates = zipWith (\(r, c) step -> (r, c, head (show (step `mod` 10)))) path [0..]
      in putIntoMaze maze updates

