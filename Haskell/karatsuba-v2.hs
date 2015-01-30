karatsuba :: Integer -> Integer -> Integer
karatsuba x y acc
  | x < 10 || y < 10 = x * y
  | otherwise        = 10 ^ ((div t 2)  * 2) * p + 10 ^ (div t 2) * r + s
                         where
                             t = max xDig yDig
                             xDig = floor $ logBase 10 (fromInteger x) + 1
                             yDig = floor $ logBase 10 (fromInteger y) + 1
                             (a, b) = split x (div t 2)
                             (c, d) = split y (div t 2)
                             p = karatsuba a c
                             s = karatsuba b d
                             r = (karatsuba (a + b) (c + d)) - p - s
split num n = (a, b)
              where
                a = div num (10 ^ n)
                b = rem num (10 ^ n)
