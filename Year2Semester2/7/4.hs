import Control.Monad.Cont;


myMap :: (a -> b) -> [a] -> Cont r [b]
myMap f []     = return []
myMap f (x:xs) = do
                 result <- myMap f xs
                 return $ (f x):result


myFilter :: (a -> Bool) -> [a] -> Cont r [a]
myFilter f []     = return []
myFilter f (x:xs) = do
                    result <- myFilter f xs
                    if (f x)
                    then return (x:result)
                    else return result