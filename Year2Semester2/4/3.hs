count1 = sum . map (\x -> mod (x + 1) 2)

count2 = length . filter (\x -> mod x 2 == 0)

count3 = foldr (\x y -> (mod (x + 1) 2) + y) 0