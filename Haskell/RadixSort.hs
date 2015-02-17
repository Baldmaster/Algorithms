-- Radix sort
--
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015
import Data.Array
import Data.Ix


type Key val    = [val]
type Bucket val = [Key val]
type Buckets val = Array val (Bucket val)

rsort :: Ix a => Int -> (a, a) -> [Key a] -> [Key a]
rsort 0       bnds l   = l
rsort p       bnds l   = rsort (p - 1) bnds (concatA (split' (p - 1) bnds l))

split' :: Ix a => Int -> (a, a) -> [Key a] -> Buckets a
split' k bnds l = accumArray f [] bnds [(x !! k, x) | x <- l]
                    where f l key = key : l

concatA :: Ix a => Buckets a -> [Key a]
concatA = (foldr rev []) . elems
  where rev []     res = res
        rev (x:xs) res = rev xs (x:res)


main = do
       print $ rsort 3 (0,9) [[2,3,2], [2,3,1], [4,2,8], [1,1,1], [2,1,3],
                              [8,2,1], [7,9,7], [3,9,8], [5,2,1]]

