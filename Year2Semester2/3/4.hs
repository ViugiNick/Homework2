data Tree = Leaf | Branch (Tree) (Tree) 

treeHeight :: Tree -> Integer
treeHeight(Leaf) = 0
treeHeight(Branch left right) = max(treeHeight left)(treeHeight right) + 1

minDistToLeaf :: Tree -> Integer
minDistToLeaf(Leaf) = 0
minDistToLeaf(Branch left right) = min(minDistToLeaf left)(minDistToLeaf right) + 1