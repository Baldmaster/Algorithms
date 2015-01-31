--
-- Merge sort
--
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015

split :: (Ord a) => [a] -> [[a]]
split []     = []
split (x:xs) = [x] : split xs

merge :: (Ord a) => [a] -> [a] -> [a]
merge [] a    = a
merge b []    = b
merge a@(x:xs) b@(y:ys)
    | x <= y    = x : (merge xs b)
    | otherwise = y : (merge a ys) 


mergepairs :: (Ord a) => [[a]] -> [[a]]
mergepairs []           = []
mergepairs x@[l]        = x
mergepairs (l1:l2:rest) = (merge l1 l2) : (mergepairs rest)

msort :: (Ord a) => [a] -> [a]
msort l          = ms (split l)
    where ms [r] = r
          ms l   = ms (mergepairs l)
