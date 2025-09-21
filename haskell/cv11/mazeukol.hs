type Maze = [String]

printMaze :: Maze -> IO ()
printMaze x = putStr (concat (map (++"\n") x))

sample1 :: Maze
sample1 = ["*********",
           "* *   * *",
           "* * * * *",
           "* * * * *",
           "*   *   *",
           "******* *",
           "        *",
           "*********"]
sample2 :: Maze
sample2 = ["       ",
           "       ",
           "  ***  ",
           "  ***  ",
           "  ***  ",
           "       ",
           "       "]
sample3 :: Maze
sample3 = ["  * *  ",
           " ##### ",
           "  ***  ",
           "  * *  ",
           "  ***  ",
           "     * ",
           "       "]
sample4 :: Maze
sample4 = ["*********",
           "*s*   *e*",
           "* *   * *",
           "* *   * *",
           "*       *",
           "******* *",
           "        *",
           "*********"]
arrow :: Maze
arrow = [ "....#....",
          "...###...",
          "..#.#.#..",
          ".#..#..#.",
          "....#....",
          "....#....",
          "....#####"]

-- Place one maze above another
above :: Maze -> Maze -> Maze
above m1 m2 = m1 ++ m2

-- Place two mazes side by side
sideBySide :: Maze -> Maze -> Maze
sideBySide m1 m2 = [a ++ b | (a, b) <- zip m1 m2]

-- Rotate maze to the right
rotateL :: Maze -> Maze
rotateL m = reverse (transposeList m)

-- Rotate maze to the left
rotateR :: Maze -> Maze
rotateR m = transposeList (reverse m)

-- Transpose a list of strings (equivalent to `Data.List.transpose`)
transposeList :: [[a]] -> [[a]]
transposeList ([]:_) = []
transposeList m = (map head m) : transposeList (map tail m)

-- Get a character from the maze
getFromMaze :: Maze -> (Int, Int) -> Char
getFromMaze m (r, c) = (m !! r) !! c

-- Put a character into the maze
putIntoMaze :: Maze -> [(Int, Int, Char)] -> Maze
putIntoMaze maze [] = maze
putIntoMaze maze ((a, b, c) : xs) =
  let rows_before = take a maze
      row_current = (maze !! max 0 (length rows_before))
      char_before = take b row_current
      char_after = drop (length char_before +1) row_current
      row_after = drop (length rows_before +1) maze
      in putIntoMaze (rows_before ++ [char_before ++ [c] ++ char_after] ++ row_after) xs
      
-- Get a rectangular part of the maze
getPart :: Maze -> (Int, Int) -> (Int, Int) -> Maze
getPart m (r, c) (h, w) = [take w (drop c (m !! i)) | i <- [r..r+h-1]]

-- Solve the maze
solveMaze :: [String] -> Int
solveMaze m =
  let
    -- Pomocné pro nalezení řádku a sloupce začátku ('s')
    startRow = head [r | (r, row) <- zip [0..] m, 's' `elem` row]
    startCol = head [c | c <- [0..length (m !! 0) - 1], m !! startRow !! c == 's']
    
    -- Směry pohybu v labyrintu (nahoru, dolů, doleva, doprava)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    -- Funkce pro kontrolu, jestli je pozice platná (uvnitř hranic a není zeď)
    isValid (x, y) =
      x >= 0 && y >= 0 && x < length m && y < length (head m) && (m !! x !! y) /= '*'
    
    -- Šířkový průzkum (BFS) pro nalezení nejkratší cesty od 's' do 'e'
    bfs :: [(Int, Int, Int)] -> Int
    bfs [] = -1
    bfs ((r, c, steps) : qs)
      | m !! r !! c == 'e' = steps
      | otherwise =
          let
            nextSteps = [(r', c', steps + 1) | (r', c') <- [(r-1, c), (r+1, c), (r, c-1), (r, c+1)], isValid (r', c')]
          in bfs (qs ++ nextSteps)

  in bfs [(startRow, startCol, 0)]