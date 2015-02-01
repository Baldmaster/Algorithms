-- Karatsuba algorithm
--
-- String implementation. Space consuming, but it works!
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015

karatsuba :: String -> String -> Integer
karatsuba x y
  | length x == 1 || length y == 1  = (read x :: Integer) * (read y :: Integer)
  | otherwise                       = ((10 ^ t) * ac) + bd + ((10 ^ t') * adbc)
    where
          (v, w)    = case xl <= yl of
                          True  -> (foldr (++) x $ replicate (yl - xl) "0", y)
                          False -> (x, foldr (++) y $ replicate (xl - yl) "0")
          (t, n)    = case rem (length v) 2 == 0 of
                          True  -> (length v, div (length v) 2)
                          False -> (length v - 1, div (length v) 2 + 1)
          t'        = div t 2
          xl        = length x
          yl        = length y
          a         = take n v
          b         = drop n v
          c         = take n w
          d         = drop n w
          ac        = karatsuba a c
          bd        = karatsuba b d
          adbc      = (+ (- ac)) . (+ (- bd)) $
                      karatsuba
                      (show $ (read a :: Integer) + (read b :: Integer))
                      (show $ (read c :: Integer) + (read d :: Integer))

