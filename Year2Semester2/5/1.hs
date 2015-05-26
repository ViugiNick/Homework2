import Control.Monad;

myPrint :: [Int] -> IO ()
myPrint [x] = print x
myPrint (x:xs) = do putStr $ show x; putStr " + "; myPrint xs

partitionIteration :: Int -> IO ()
partitionIteration x = partitionIteration x 0 []
					   where partitionIteration x y ans | x <= 0 = do myPrint ans; putStr "\n"
													    | otherwise = do
													                when ((y > 0) && (y <= x)) $ partitionIteration (x - y) y (y:ans)					   						
													                when (y < x) $ partitionIteration x (y + 1) ans