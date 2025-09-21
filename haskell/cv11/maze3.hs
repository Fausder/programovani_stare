type Maze = [String]

                
printMaze :: Maze -> IO ()
printMaze x = putStr (concatMap (++ "\n") x)

minimaps :: Maze -> (Int, Int) -> [(Char, Int)] -> Maze
minimaps maze start path = concatMap formatMiniMap (createMiniMaps maze start path)

-- Vytvoření seznamu mini-map
createMiniMaps :: Maze -> (Int, Int) -> [(Char, Int)] -> [Maze]
createMiniMaps maze start [] = [createMiniMap maze start]
createMiniMaps maze start ((dir, len):steps) =
  let end = move start dir len
  in createMiniMap maze start : createMiniMaps maze end steps

-- Vytvoření jednotlivé mini-mapy
createMiniMap :: Maze -> (Int, Int) -> Maze
createMiniMap maze (r, c) =
  let part = getPart maze (r - 1, c - 1) (3, 3)
  in markCenter part

-- Označení středu mini-mapy tečkou
markCenter :: Maze -> Maze
markCenter m =
  let (r1:r2:r3:[]) = m
      r2' = take 1 r2 ++ "." ++ drop 2 r2
  in [r1, r2', r3]

-- Výběr části bludiště (zadané souřadnicemi)
getPart :: Maze -> (Int, Int) -> (Int, Int) -> Maze
getPart maze (r, c) (h, w) =
  [ [if r' >= 0 && r' < length maze && c' >= 0 && c' < length (head maze)
       then maze !! r' !! c'
       else ' '
     | c' <- [c .. c + w - 1] ]
   | r' <- [r .. r + h - 1] ]

-- Pohyb z aktuální pozice
move :: (Int, Int) -> Char -> Int -> (Int, Int)
move (r, c) 'd' len = (r + len, c)
move (r, c) 'u' len = (r - len, c)
move (r, c) 'l' len = (r, c - len)
move (r, c) 'r' len = (r, c + len)
move pos _ _        = pos

-- Formátování výstupní mini-mapy
formatMiniMap :: Maze -> Maze
formatMiniMap m = ["---------"] ++ m ++ ["---------"]