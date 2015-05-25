printHelp :: IO ()
printHelp = do
    putStrLn "0 - exit"
    putStrLn "1 x - add x"
    putStrLn "2 x - delete x"
    putStrLn "3 - print"
    putStrLn "4 - help"

addElement :: [String] -> String -> [String]
addElement [] element = [element]
addElement (x:xs) element = if (element <= x)
                         then element:x:xs
                         else x:(addElement xs element)
    
removeElement :: [String] -> String -> [String]
removeElement [] element = []
removeElement (x:xs) element = if(element == x)
    						   then xs
							   else x:(removeElement xs element)
    
iteration :: [String] -> IO ()
iteration l = do
    com <- getLine
    case (com !! 0) of
        '0' -> return ()
        '1' -> iteration (addElement l (drop 2 com))
        '2' -> iteration (removeElement l (drop 2 com))
        '3' -> do putStrLn (show l); iteration l
        '4' -> printHelp
     

main = do 
    printHelp
    iteration []