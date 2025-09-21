--1.1
countries :: [(String, Int)] -> Int -> [String]
countries [] _ = []
countries ((x, y):xs) n
    | y > n = x : countries xs n
    | otherwise = countries xs n

--1.2
complement :: Int -> Int -> [Int] -> [Int]
complement x y a = let odeber = filter (`notElem` a)
                    in odeber [x..y]

--1.3
merge :: Ord a => [a] -> [a] -> [a]
merge xs [_] = xs
merge [_] ys = ys
merge (x:xs) (y:ys)
    | x <= y = x : merge xs (y:ys)
    | otherwise = y : merge (x:xs) ys


--2.1
select :: [(String, Float)] -> String
select [] = []
select [x] = fst x
select ((x1, y1):(x2, y2):xs)
    | y2 > y1 = select ((x2, y2):xs)
    | otherwise = select ((x1, y1):xs)

-- 2.2
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

factorials :: Int -> Int -> [(Int, Int)]
factorials x y
    | y > x = []
    | otherwise = [(n, factorial n) | n <- [x..y]]

--2.3
splitWith :: Eq a => [a] -> [a] -> [[a]]
splitWith [] _ = []
splitWith str del = splitHelper str
  where
    splitHelper [] = []
    splitHelper s =
      let (word, rest) = break (`elem` del) s
      in if null word
         then splitHelper (drop 1 rest)
         else word : splitHelper (drop 1 rest)


--3.1
accounts :: [(String, Int)] -> [String]
accounts [] = []
accounts ((x, y):xs)
    | y > 0 = x : accounts xs
    | otherwise = accounts xs

--3.2
mostFrequent :: [Int] -> Int
mostFrequent xs = snd (maximum [(length (filter (== x) xs), x) | x <- xs])

--3.3
getHashMap :: Eq a => [a] -> (a -> Int) -> [(Int, [a])]
getHashMap [] _ = []
getHashMap (x:xs) hash = 
  let (key, rest) = span (\y -> hash y == hash x) (x:xs)
  in (hash x, key) : getHashMap rest hash


-- ??
convert :: [(String, Int, Float)] -> [(String, Float)]
convert [] = []
convert ((x, y, z):xs) = (x, fromIntegral y * z) : convert xs

-- ??.2
replaceByRepeat :: String -> Char -> Int -> String
replaceByRepeat str ch n = concat [if x == ch then x : replicate (n-1) ch else [x] | x <- str]

-- ??.3
change :: [a] -> [(Int, Int)] -> [a]
change = foldl f
  where
    f xs (i, n) =
        let (a, b) = splitAt i xs
            (c, d) = splitAt n b
        in a ++ reverse c ++ d

-- ?? 2.1
countries' :: [(String, Int)] -> Int -> [String]
countries' [] _ = []
countries' ((x, y) : xs) n
    | y > n = x : countries' xs n
    | otherwise = countries' xs n

-- ?? 2.2
intersection3 :: Eq a => [a] -> [a] -> [a] -> [a]
intersection3 a b c = [d | d <- c, d `elem` b, d `elem` a]

-- ?? 2.3
merge' :: Ord a => [a] -> [a] -> [a]
merge' xs [_] = xs
merge' [_] ys = ys
merge' (x:xs) (y:ys)
    | x <= y = x : merge' xs (y:ys)
    | otherwise = y : merge' (x:xs) ys

--5.1
filter' :: [(String, Int)] -> Int -> [String]
filter' [] _ = []
filter' ((x, y) : xs) n
    | y < n = x : filter' xs n
    | otherwise = filter' xs n

--5.2
positions :: String -> Char -> [Int]
positions s c = [i | (i, x) <- zip [0..] s, x == c]

--5.3
unique :: Eq a => [a] -> [a] -> [a] -> [a]
unique a b c = [x | x <- a, not (x `elem` b || x `elem` c)] 
            ++ [x | x <- b, not (x `elem` a || x `elem` c)]
            ++ [x | x <- c, not (x `elem` a || x `elem` b)]

--6.1
average :: [(String, Int)] -> Double
average xs = fromIntegral (sum (map snd xs)) / fromIntegral (length xs)

--6.2
changes :: Eq a => [(a,b)] -> a -> b -> [(a,b)]
changes xs b c = [(k, if k == b then c else v) | (k, v) <- xs]

--6.3
buildText :: [(String, Int)] -> String
buildText = concatMap (\(a, n) -> concat (replicate n a))