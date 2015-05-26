listGenerator :: Int -> [[Int]]
listGenerator n | n <= 0 = []
listGenerator 1 = [[1],[2],[3]]
listGenerator n = do
	x <- [1, 2, 3]
	map (x:) (listGenerator (n - 1))