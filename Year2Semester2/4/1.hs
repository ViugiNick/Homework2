import Data.Maybe


data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findElement :: Tree a -> (a -> Bool) -> Maybe [a]

findElement (Leaf x) f = if (f x) then Just [x] else Nothing

findElement (Branch l x r) f = if (f x)
                               then Just [x]
                               else case (findElement l f, findElement r f) of
                                                       (Just y, _) -> Just y
                                                       (_, Just y) -> Just y
                                                       (_, _) -> Nothing
