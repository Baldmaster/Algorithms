-- Karatsuba algorithm
--
-- String implementation.
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015

karatsuba :: String -> String -> Integer
karatsuba x y
  | length x == 1 || length y == 1  = (read x :: Integer) * (read y :: Integer)
  | otherwise                       = ((10 ^ t) * ac) + bd + ((10 ^ t') * adbc)
    where
          (v, w)    = if xl <= yl 
                          then (foldr (++) x $ replicate (yl - xl) "0", y)
                          else (x, foldr (++) y $ replicate (xl - yl) "0")
          (t, n)    = if rem (length v) 2 == 0
                          then (length v, div (length v) 2)
                          else (length v - 1, div (length v) 2 + 1)
          t'        = div t 2
          xl        = length x
          yl        = length y
          a         = take n v
          b         = drop n v
          c         = take n w
          d         = drop n w
          ac        = (karatsuba a c)
          bd        = (karatsuba b d)
          adbc      = (+ (- ac)) . (+ (- bd)) $
                      karatsuba
                      (show $ (read a :: Integer) + (read b :: Integer))
                      (show $ (read c :: Integer) + (read d :: Integer))
