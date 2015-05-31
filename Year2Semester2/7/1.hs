import Control.Exception.Base;

help :: IO ()
help = do
    putStr "0 : exit\n"
    putStr "1 name number : add node\n"
    putStr "2 name : find node with this name\n"
    putStr "3 number : find node with this number\n"
    putStr "4 file : print to file\n"
    putStr "5 file : load from file\n"

type PhoneBook = [(String, [String])]

add :: (String, String) -> PhoneBook -> PhoneBook
add (nm, nb) p = case (lookup nm p) of
                        Just _ -> map (\(x,y) -> if x == nm then (x, nb:y) else (x,y)) p
                        Nothing -> (nm, [nb]):p

findName :: String -> PhoneBook -> Maybe [String]
findName n l = case res of
    [] -> Nothing
    _ -> Just (map (fst) res)
    where res = filter (\(x,y) -> n `elem` y) l

iteration :: PhoneBook -> IO ()
iteration mainBook = do
    com <- getLine
    case (com !! 0) of
        '0' -> return ()
        '1' -> case (words $ drop 2 com) of
                                  [name, number] -> do 
                                             putStrLn "OK";
                                             iteration (add (name, number) mainBook);
                                  _ -> fail "Error"
        
        '2' -> do case (words $ drop 2 com) of
                                  [name] -> do 
                                            putStrLn $ show (lookup name mainBook);
                                            putStrLn "OK";
                                            iteration mainBook;
                                  _ -> fail "Error"
        
        '3' -> do case (words $ drop 2 com) of
                                  [number] -> do 
                                            putStrLn $ show (findName number mainBook);
                                            putStrLn "OK";
                                            iteration mainBook;
                                  _ -> fail "Error"
        
        '4' -> do case (words $ drop 2 com) of
                    [filename] -> do 
                                  writeFile filename (show mainBook);
                                  putStrLn "OK";
                                  iteration mainBook;
                    _ -> fail "Error"
        
        '5' -> do
                file <- readFile (drop 2 com)
                newBook <- readIO file :: IO PhoneBook;
                putStrLn "OK"
                iteration newBook;
        _   -> fail "Error"
    `catch` (\e -> do putStrLn (show (e :: IOError));iteration mainBook)

main = do help; iteration []