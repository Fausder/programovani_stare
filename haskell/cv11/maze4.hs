type Maze = [String]

ms :: Maze
ms =      ["*.......",
           ".....*..",
           "..*.*#..",
           "..*.*#..",
           "..***#..",
           ".#####..",
           "......*.",
           "........"]


printMaze :: Maze -> IO ()
printMaze x = putStr (concat (map (++"\n") x))

-- Funkce na spočítání min kolem každé volné buňky
minesInMaze :: Maze -> Maze
minesInMaze maze = [ [ processCell (x, y) | x <- [0 .. length (maze !! 0) - 1] ] | y <- [0 .. length maze - 1] ]
  where
    processCell (x, y)
      | maze !! y !! x == '*' = '*'
      | maze !! y !! x == '#' = '#'
      | otherwise = let count = countMines (x, y) in if count == 0 then '.' else head (show count)

    -- Spočítá počet min v okolí buňky
    countMines (x, y) = length [ () | dx <- [-1..1], dy <- [-1..1], isMine (x + dx, y + dy) ]
    isMine (x, y) = x >= 0 && y >= 0 && y < length maze && x < length (maze !! 0) && maze !! y !! x == '*'
