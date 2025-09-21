-- funkce putStrLn 
-- putStrLn (concat (map (++"\n")))
-- hledani nejkratší cesty označit start 0 sousedy 1 sousedy 1 označit 2 a pokažde 
-- zpracovávám to číšslo (sousedy 9 označím 10 atd) a to číslo které se dostane to cíle bdue nejkratší cesta, (x,y,0) je start a přidávám dokud to neoznačí cíl

data Expr = Num Int
    | Add Expr Expr
    | Sub Expr Expr
    | Mul Expr Expr
    | Div Expr Expr
    | Var Char
    deriving (Eq)

--(1+3)*3
ex1 :: Expr
ex1 = Mul (Add (Num 1) (Num 2)) (Num 3)

-- 1 + 2 * 3
ex2 :: Expr
ex2 = Add (Num 1) (Mul (Num 2) (Num 3))

-- x + x*x
--ex3 :: Expr
--ex3 = Add (Var `x`) (Mul (Var `x`) (Var `x`))

eval :: Expr -> Int
eval (Num x) = x
eval (Add l r) = eval l + eval r
eval (Sub l r) = eval l - eval r
eval (Mul l r) = eval l * eval r
eval (Div l r) = eval l `div` eval r

showExpr :: Expr -> String
showExpr (Num x) = show x
showExpr (Var x) = [x]
showExpr (Add l r) = "(" ++ showExpr l ++ "+" ++ showExpr r ++")"
showExpr (Sub l r) = "(" ++ showExpr l ++ "-" ++ showExpr r ++")"
showExpr (Mul l r) = "(" ++ showExpr l ++ "*" ++ showExpr r ++")"
showExpr (Div l r) = "(" ++ showExpr l ++ "`div`" ++ showExpr r ++")"

instance Show Expr where
    show :: Expr -> String
    show = showExpr

instance Ord Expr where
    compare :: Expr -> Expr -> Ordering
    compare x y  = compare (eval x) (eval y)

deriv :: Expr -> Char -> Expr
deriv (Num x) y = Num 0
deriv (Var x) y | x==y = Num 1
                | otherwise = Num 0
deriv (Add u v) y = Add (deriv u y) (deriv v y)
deriv (Sub u v) y = Sub (deriv u y) (deriv v y)
deriv (Mul u v) y = Add (Mul(deriv u y)v) (Mul(deriv v y)u)
deriv (Div u v) y = Div (Sub (Mul(deriv u y)v) (Mul(deriv v y)u)) (Mul v v)



data Tree a = Leaf a
    | Branch a (Tree a) (Tree a)

t1 :: Tree Int
t1 = Branch 1 (Branch 2 (Leaf 3) (Leaf 4)) (Leaf 5)

t2 :: Tree String
t2 = Leaf "grgr"

sum' :: Tree Int -> Int 
sum' (Leaf x) = x
sum' (Branch x l r) = sum' l + sum' r + x

toList :: Tree a -> [a] 
toList (Leaf x) = [x]
toList (Branch x l r) = toList l ++ [x] ++ toList r

depthTree :: Tree a -> Int
depthTree (Leaf x) = 1
depthTree (Branch x l r) = 1 + max (depthTree l) (depthTree r)