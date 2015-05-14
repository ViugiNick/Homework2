goodBracket :: [Char] -> Bool
goodBracket' :: ([Char], [Char]) -> Bool
goodBracket string = goodBracket' (string, "")


goodBracket' ("", "") = True
goodBracket' ("", _) = False

goodBracket' ('(':xs, stack) = goodBracket' (xs, '(':stack)
goodBracket' ('[':xs, stack) = goodBracket' (xs, '[':stack)
goodBracket' ('{':xs, stack) = goodBracket' (xs, '{':stack)

goodBracket' (')':xs, '(':stack) = goodBracket' (xs, stack)
goodBracket' (']':xs, '[':stack) = goodBracket' (xs, stack)
goodBracket' ('}':xs, '{':stack) = goodBracket' (xs, stack)

goodBracket' (_, _) = False