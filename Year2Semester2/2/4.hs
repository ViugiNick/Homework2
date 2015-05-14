firstPosition :: ([Integer], Integer) -> Integer
firstPosition([], n) = -1

firstPosition(list, n) = if head list == n
                then 1
                else let answer = firstPosition(tail list, n)
                     in if answer == -1
                        then -1
                        else answer + 1