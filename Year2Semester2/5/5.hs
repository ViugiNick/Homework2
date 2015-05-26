import Control.Monad;


isGood :: (Ord a) => (a,a,a) -> Maybe a
isGood (x1,x2, x3)
    | (x1 < x2 && x2 > x3) = Just x2
    | otherwise = Nothing

find :: (Ord a) => [a] -> Maybe a
find (x1:x2:x3:xs) = mplus (isGood (x1,x2,x3)) (find (x2:x3:xs))
find [] = Nothing