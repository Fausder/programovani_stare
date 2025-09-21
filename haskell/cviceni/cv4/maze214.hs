type Maze = [String]

printMaze :: Maze -> IO ()
printMaze x = putStr (concatMap (++ "\n") x)

getFromMaze :: Maze -> (Int, Int) -> Char
getFromMaze maze (row, col) = (maze !! row) !! col

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