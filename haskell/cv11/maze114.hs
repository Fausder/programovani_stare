type Maze = [String]

printMaze :: Maze -> IO ()
printMaze x = putStr (concat (map (++"\n") x))

markPath :: Maze -> (Int, Int) -> [Char] -> [(Int, Int)]
markPath m (r, c) [] = [(r, c)]
markPath m (r, c) (step:steps) =
  let (dr, dc) = case step of
                   'd' -> (1, 0)
                   'u' -> (-1, 0)
                   'l' -> (0, -1)
                   'r' -> (0, 1)
                   _   -> (0, 0)
      newPos = (r + dr, c + dc)
  in newPos : markPath m newPos steps
