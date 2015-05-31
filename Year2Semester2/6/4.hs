import Control.Monad.State;
import Test.QuickCheck;

data Graph v e = Graph [(Int, v)] [(Int, Int, e)]

changeDistance :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
changeDistance e (newVal1, newVal2) = map (\(x, y) -> if (x == newVal1) then (newVal1, newVal2) else (x, y)) e

getMin :: [(Int, Int)] -> (Int, Int)
getMin (l1:l2:ls)  | (snd l1) < (snd l2)   = getMin (l1:ls)
                   | otherwise = getMin (l2:ls)
getMin (l1:[]) = l1

findingIteration :: [(Int, Int)] -> [(Int, Int, Int)] -> Int -> [(Int, Int)]
findingIteration v e start
    | length v == 1 = v
    | otherwise  = case (lookup start v) of
                    Just mark -> let help ((f, t, c):es)
                                        | start == f = do                                             
                                            notvis <- get
                                            case (lookup t notvis) of
                                                Nothing -> help es
                                                Just m  -> if m < (mark + c)
                                                           then 
                                                                    help es
                                                           else do
                                                                    put $ changeDistance notvis (t, mark + c)
                                                                    help es
                                        | otherwise  = help es
                                     help [] = return []
                                 in
                                 let notVisited = filter (\(x,y) -> x /= start) (execState (help e) v) in
                                 let p = getMin notVisited in (getMin v):(findingIteration notVisited e (fst p))



findPath :: Graph v Int -> Int -> [(Int, Int)]
findPath (Graph v e) start = findingIteration (map (\(x,y) -> if x == start then (x, 0) else (x, (maxBound :: Int))) v) e start

inf = maxBound :: Int
testgraph = Graph [(0, 0), (1, 0), (2, 0), (3, 0), (4, 0)] [(0, 1, 10), (1, 2, 3), (2, 3, 3), (0, 4, 5), (4, 3, 13)] :: Graph Int Int

main = quickCheck(findPath testgraph 0 == [(0, 0), (4, 5), (1, 10), (2, 13), (3, 16)])
