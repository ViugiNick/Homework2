data Product = Book {
                        name :: String,    
                        author :: String,
                        price :: Int
                    }
                    |
               Magazine {
                            name :: String,
                            year :: Int,
                            editionNumber :: Int,
                            price :: Int
                        }

productList :: [Product] -> Int
productList = foldr ((+) . price) 0