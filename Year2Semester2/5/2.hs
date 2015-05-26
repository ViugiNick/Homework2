satisfies :: [a] -> (a -> Bool) -> Bool
satisfies xs cond = (length xs) == (length $ filter cond xs)