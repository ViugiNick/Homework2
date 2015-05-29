import Control.Monad.State;

data Tree = Empty | Node Char Tree Tree deriving(Eq, Show)

printTree :: Tree -> String
printTree Empty = "e"
printTree (Node x l r) = 'n':x:(printTree l ++ printTree r)

createTree :: String -> Tree
createTree str = let create  = do
                                 state <- get
                                 case state of
                                 	('n':x:xs) -> do
                                 		put xs
                                 		l <- create
                                 		r <- create
                                 		return(Node x l r)
                                 	('e':xs) -> do
                                 		put xs
                                 		return Empty
                 in evalState create str


test1 = "n1n2een3ee"
test2 = Node '1' (Node '2' Empty Empty) (Node '3' Empty Empty)