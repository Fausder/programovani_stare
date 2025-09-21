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


changes :: Maze -> (Int, Int) -> [(Char, Int)] -> [(Int, Int)]
changes maze start path = tail $ snd $ foldl helper (start, [start]) path
  where
    helper :: ((Int, Int), [(Int, Int)]) -> (Char, Int) -> ((Int, Int), [(Int, Int)])
    helper ((r, c), acc) (dir, len) =
      let newPos = case dir of
            'd' -> (r + len, c)
            'u' -> (r - len, c)  
            'l' -> (r, c - len) 
            'r' -> (r, c + len) 
            _   -> (r, c)        
      in (newPos, acc ++ [newPos])
