maxSum (i1:i2:i) = maxSum' (i2:i) (i1 + i2, 2) 1
maxSum _ = 0

maxSum' (i1:i2:i) (ans, s) t | ans >= i1 + i2 = maxSum' (i2:i) (ans, s + 1) t
                             |  ans < i1 + i2 = maxSum' (i2:i) (i1 + i2, s + 1) s

maxSum' _ _ t = t
