take' :: Int -> [a] -> [a]
take' 0 xs = []
take' i [] = []
take' i (x:xs) = x : take' (i-1) xs

drop' :: Int -> [a] -> [a]
drop' 0 xs = xs
drop' i [] = []
drop' i (x:xs) = drop' (i-1) xs

minimum' ::Ord a => [a] -> a
minimum' (x:xs) = tmp x xs where
    tmp am [] = am
    tmp am (x:xs) | am < x = tmp am xs
                  | am >= x = tmp x xs

minimum'' ::Ord a => [a] -> a
minimum'' (x:xs) = tmp x xs where
    tmp am [] = am
    tmp am (x:xs) = tmp (min am x) xs

minimum''' ::Ord a => [a] -> a
minimum''' [x] = x
minimum''' (x:y:z) = minimum'''(min x y :z)

divisors :: Int -> [Int]
divisors n = tmp n where
  tmp 0 = []
  tmp x | n `mod` x == 0 = x: tmp (x-1)
        | otherwise = tmp (x-1)

--divisors' n = filter test [1..n] where
    test x = n 'mod' x == 0
                 
--divisors' n = [x |x<-[1..n], n 'mod' x == 0]


zipThem:: [a] -> [b] -> [(a,b)]
zipThem (x:xs) (y:ys) = (x,y) : zipThem xs ys
zipThem _ _:[]
