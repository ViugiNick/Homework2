import System.Random;
import Control.Monad.State;
import Data.Time.Clock.POSIX;

data Tree a = Leaf a | Branch (Tree a) a (Tree a) deriving (Show)

randomize :: Tree a -> Int -> Tree Int
randomize tree v = let randomizeHelp (Branch l x r) = do
                                                    gen <- get
                                                    let (newValue, newgen) = random gen
                                                    put newgen
                                                    randL <- randomizeHelp l
                                                    randR <- randomizeHelp r
                                                    return (Branch randL newValue randR)

                       randomizeHelp (Leaf a) = do
                                            gen <- get
                                            let (newValue, newgen) = random gen
                                            put newgen
                                            return (Leaf newValue)

                   in evalState (randomizeHelp tree) (mkStdGen v)

inputTree = Branch (Leaf 1) (1) (Leaf (1))

main = do
    seed <- round `fmap` getPOSIXTime
    putStrLn . show $ randomize inputTree seed