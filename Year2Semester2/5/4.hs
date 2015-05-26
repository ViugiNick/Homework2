pairwiseProducts :: Int -> [Int]
pairwiseProducts n = [1..n] >>= (\x -> map(x*) [1..n])