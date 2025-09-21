f [1] = 0
f [2,4,5] = 0
f [x] = 0
f [x,y,2,z] = 0       --4:[1,2,3] = [4,1,2,3]
                      --[1,2,3] = vzniklo jako 1:[2,3]
length' :: [a] -> Int
length' [] = 0
length' (x:xs) = 1 + length' xs

sumIt :: [Int] -> Int
sumIt [] = 0
sumIt (x:xs) = x + sumIt xs

getHead :: [a] -> a
getHead [] = error "Nejde to"
getHead (x:xs) = x

getLast :: Eq a => [a] -> [a]
getLast [] = error "Nejde to"
getLast (x:xs) | xs == [] = xs
               | otherwise = getLast xs

getTail :: [a] -> [a]
getTail (_:xs) = xs

getInit :: [a] -> [a]
getInit [x] = []
getInit (x:xs) = x : getInit xs

nonZeros :: [Int] -> [Int]
nonZeros []=[]
nonZeros (x:xs) |x == 0 = nonZeros xs 
                |otherwise = x: nonZeros xs
                
isElement :: Eq a => a -> [a] -> Bool
isElement a [] = False
isElement a (x:xs) | x == a = True
                   | otherwise = isElement a xs

combine :: [a] -> [a] -> [a]
combine [] a = a
combine (x:xs) a = x : combine xs a

reverse2 :: [a] -> [a]
reverse2 [] = []
reverse2 (x:xs) = x : []       --du dodělat aby měl složitost že projde jen jednou

reverse' :: [a]->[a]
reverse' xs = tmp xs [] where
    tmp [] ys = ys
    tmp (x:xs) ys = tmp xs (x:ys)