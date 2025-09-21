quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort [x] = [x]
quicksort (x:xs) = filter (<x) xs

oddList :: Int -> Int -> [Int]
oddList a b | a > b = []
            | mod a 2 == 1 = a: oddList (a+1) b
            | otherwise = oddList (a+1) b

union :: Eq a => [a] -> [a] -> [a]
union  xs ys = xs ++ [y |y<-ys, not(y `elem` xs)]

intersection :: Eq a => [a] -> [a] -> [a]
intersection xs ys = [y |y<-ys, y `elem` xs]

split :: [(a,b)] -> ([a],[b])
split xs = tmp xs ([],[]) where
    tmp [] ab = ab
    tmp ((a,b):xs) (as,bs) = tmp xs (as++[a], bs++[b])


partition :: (a -> Bool) -> [a] -> ([a],[a])
partition f xs = tmp xs ([],[]) where
    tmp [] ab = ab
    tmp (x:xs) (as,bs) | f x = tmp xs (as++[x], bs )
                       | otherwise = tmp xs (as, bs++[x] )

partition' f xs = ( filter f xs, filter (\y-> not(f x)) xs)



countThem :: String -> [(Char, Int)]
unique [] = []
unique (x:xs) = x : unique (filter (/=x) xs)
countThem all = let
    allUnique = unique all
    in [(x, lenght (filter (==x) all)) |x <- allUnique]
