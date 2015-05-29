data BinarySearchTree a = Node a (BinarySearchTree a) (BinarySearchTree a) 
                         | Empty 
                          deriving (Eq, Show)

add :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
add (Empty) elem = Node elem Empty Empty
add (Node x l r) elem | elem < x = Node x (add l elem) r
                      | elem > x = Node x l (add r elem)
                      | (elem == x) = Node x l r

search :: (Ord a) => BinarySearchTree a -> a -> Bool
search (Empty) elem = False
search (Node x l r) elem | elem < x = search l elem
                         | elem > x = search r elem
                         | (elem == x) = True

findMin :: (Ord a) => BinarySearchTree a -> a
findMin tree = case tree of
        (Node x Empty r) -> x
        (Node x l r)     -> findMin l
        (Empty)          -> error "tree is empty"

remove :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
remove (Empty) elem = Empty
remove (Node x l r) elem | elem < x = Node x (remove l elem) r
                         | elem > x = Node x l (remove r elem)
                         | (elem == x) = case (l,r) of
                                        (Empty, Empty)            -> Empty
                                        (Empty, _)                -> r
                                        (_, Empty)                -> l
                                        
                                        (_, Node val Empty tmp)   -> Node val l tmp
                                        (_, Node val lt rt)         -> Node subtree l (remove r subtree) where subtree = findMin lt
                                         

size :: BinarySearchTree a -> Int
size Empty = 0
size (Node x l r) = 1 + size l + size r

height :: BinarySearchTree a -> Int
height Empty = 0
height (Node x l r) = 1 + max(height l) (height r)

testtree = Empty `add` 1 `add` 2 `add` 0