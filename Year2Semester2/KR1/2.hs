data Tree a = Leaf a
              | Branch (Tree a) a (Tree a)

helper :: Tree Int -> [Int] -> [Int]
helper (Leaf a) answer = if(a < 0) then a : answer
                               else answer

helper(Branch leftT a rightT) answer = if(a < 0) then a : (helper rightT (helper leftT answer))
                                       else helper rightT (helper leftT answer) 


answer :: Tree Int -> [Int]
answer input = helper input [] 