newtype Polynom = Polynom [Int] deriving (Eq)

sign :: Int -> String
sign x | x > 0 = "+"
       | otherwise = ""

instance Show Polynom where
         show (Polynom x) = showHelper x 0 where
              showHelper [] n = ""
              showHelper (xf:xs) n = printMonome xf n ++ showHelper xs (n + 1)

printMonome :: Int -> Int -> String
printMonome 0 _ = ""
printMonome x 0 = show x
printMonome x 1 = sign x ++ show x ++ "x"
printMonome x n = sign x ++ show x ++ "x^" ++ show n

add :: Polynom -> Polynom -> Polynom
add (Polynom x1) (Polynom x2) = let addHelp (x1f:x1s) (x2f:x2s) = (x1f + x2f) : addHelp x1s x2s
                                    addHelp [] x = x
                                    addHelp x [] = x
                     in Polynom (addHelp x1 x2)

sub :: Polynom -> Polynom -> Polynom
sub (Polynom x1) (Polynom x2) = let subHelp (x1f:x1s) (x2f:x2s) = (x1f - x2f) : subHelp x1s x2s
                                    subHelp [] l = map(0-) l
                                    subHelp l [] = l
                     in Polynom (subHelp x1 x2)

myTake :: Int -> [Int] -> [Int]
myTake n l
    | n > length l = myTake n (l ++ [0])
    | otherwise = take n l
                     
mult :: Polynom -> Polynom -> Polynom
mult (Polynom x1) (Polynom x2) = Polynom [sum $ zipWith (*) (myTake n x1) (reverse $ myTake n x2) 
                          | n <- [1..(length x1 + length x2)]]

test1 = Polynom[1, 0, 1]
test2 = Polynom[0, 1, 0] 