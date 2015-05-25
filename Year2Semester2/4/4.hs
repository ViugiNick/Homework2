checkIfUnique :: (Eq a) => [a] -> Bool

checkIfUnique [] = True
checkIfUnique (el:l) = if (elem el l) then False else checkIfUnique l