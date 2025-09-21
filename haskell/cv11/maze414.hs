type Maze = [String]

printMaze :: Maze -> IO ()
printMaze x = putStr (concat (map (++"\n") x))

ms :: Maze
ms =      ["*.......",
           ".....*..",
           "..*.*#..",
           "..*.*#..",
           "..***#..",
           ".#####..",
           "......*.",
           "........"]

countMines :: Maze -> (Int, Int) -> Int
countMines maze (x, y) = length [() | dx <- [-1..1], dy <- [-1..1], isMine (x + dx, y + dy)]
  where
    isMine (x', y') = x' >= 0 && y' >= 0 && y' < length maze && x' < length (head maze) && maze !! y' !! x' == '*'

countAllMines :: Maze -> Int
countAllMines maze = length [() | row <- maze, cell <- row, cell == '*']
