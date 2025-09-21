isPrime2 :: Int -> Bool
isPrime2 n = tmp n (n-1)

tmp n 1 = True
tmp n index | mod n index == 0 = False
            | otherwise = tmp n (index - 1)



















isprime :: Int -> Bool
isPrime n | n == 1 = False
          | n == (div n n == 1) = True










isPrime :: Int -> Bool
isPrime 1 = False
isPrime y = isPrimeTest y (y-1) where
  isPrimeTest _ 1 = True 
  isPrimeTest n x | n `mod` x ==0 = False
                  | otherwise = isPrimeTest n (x-1)
