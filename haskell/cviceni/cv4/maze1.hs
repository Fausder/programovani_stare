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
                
printMaze :: Maze -> IO ()
printMaze x = putStr (concatMap (++ "\n") x)

-- Funkce pro vyznačení cesty v bludišti
markPath :: Maze -> (Int, Int) -> [Char] -> Maze
markPath maze start steps =
    let path = markSteps start steps
    in putIntoMaze maze path

-- Pomocná funkce pro výpočet souřadnic a znaků
markSteps :: (Int, Int) -> [Char] -> [(Int, Int, Char)]
markSteps start steps = 
    helper steps start '+' []
  where
    helper [] _ _ acc = acc -- Žádné další kroky, vrátí seznam
    helper (step:rest) (r, c) prevSymbol acc =
        let
            (dr, dc, currSymbol) = case step of
                'd' -> (1, 0, '|')
                'u' -> (-1, 0, '|')
                'l' -> (0, -1, '-')
                'r' -> (0, 1, '-')
                _   -> (0, 0, '?') -- Nepodporovaný krok
            newPos = (r + dr, c + dc)
            symbol = if prevSymbol /= currSymbol then '+' else currSymbol
        in helper rest newPos currSymbol (acc ++ [(r, c, symbol)])

-- Funkce pro vložení znaků do bludiště
putIntoMaze :: Maze -> [(Int, Int, Char)] -> Maze
putIntoMaze maze [] = maze
putIntoMaze maze ((r, c, char):rest) =
    let 
        rowsBefore = take r maze
        currentRow = maze !! r
        charBefore = take c currentRow
        charAfter = drop (c + 1) currentRow
        updatedRow = charBefore ++ [char] ++ charAfter
        rowsAfter = drop (r + 1) maze
    in putIntoMaze (rowsBefore ++ [updatedRow] ++ rowsAfter) rest
