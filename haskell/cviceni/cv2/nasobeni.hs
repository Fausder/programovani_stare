mult :: Int -> Int -> Int
mult 0 y = 0
mult x y = mult (x-1) y + y 