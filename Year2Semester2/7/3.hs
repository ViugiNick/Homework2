import Data.Char;
import Control.Monad.State;

data HashTable key val = HashTable {hash :: (key -> Int), table :: [(Int, val)]}

add :: key -> val -> HashTable key val -> HashTable key val
add k v (HashTable f t) = HashTable f (addHelper (f k) t) where
                                       addHelper x (l:ls)    | x < fst l  = (x, v) : l : ls
                                                             | x > fst l  = l : (addHelper x ls)
                                                             | otherwise  = ls
                                       addHelper x [] = [(x, v)]

find :: key -> HashTable key val -> Maybe val
find k (HashTable _ []) = Nothing
find k (HashTable f t) =       findHelper (f k) t where 
                               findHelper res (l:ls) | fst l < res    = findHelper res ls
                                                     | fst l == res   = Just (snd l)
                                                     | otherwise      = Nothing

remove :: key -> HashTable key val -> HashTable key val

remove k (HashTable f t) = HashTable f (removeHelper (f k) t) where
    removeHelper x (l:ls) | x < fst l  = l:ls
                          | x > fst l  = removeHelper x ls
                          | otherwise  = ls
    removeHelper x [] = []
