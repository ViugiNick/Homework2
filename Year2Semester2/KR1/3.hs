posOfElement :: [Int] -> Int -> Int

posOfElement xs n 
                  | prefix == xs = -1
                  | otherwise = length(prefix) + 1
             where
	          prefix = takeWhile (/= n) xs  
 