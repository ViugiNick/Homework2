primal :: Int -> Int -> Bool 
primal x 1 = True 
primal x n = if (gcd x n /= 1)  then False else primal x (n - 1) 

answer = [x | x <- [2..], primal x (x - 1)]