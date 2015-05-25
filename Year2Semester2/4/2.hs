data Tree a = Leaf a | Branch (Tree a) a (Tree a)

treeFold :: Tree a -> (b -> a -> b) -> b -> b
treeFold (Leaf a) f s = f s a
treeFold (Branch l a r) f s = treeFold r f (treeFold l f (f s a))