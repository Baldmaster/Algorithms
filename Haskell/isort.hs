-- Insertion sort
--
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015
--

insert :: (Ord a) => a -> [a] -> [a]
insert key []                   = [key]
insert key l@(x:xs) | key <= x  = key : l
                    | otherwise = x : (insert key xs)

isort :: (Ord a) => [a] -> [a]
isort xs = foldr insert [] xs
