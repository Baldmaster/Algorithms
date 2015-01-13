-- Set
--
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015
--
module Set(Set, inSet, addSet, delSet, emptySet, setEmpty) where

newtype Set a = S [a] deriving Show

emptySet :: Set a
setEmpty :: Set a -> Bool
inSet    :: (Ord a) => a -> Set a -> Bool
delSet   :: (Ord a) => a -> Set a -> Set a
addSet   :: (Ord a) => a -> Set a -> Set a

emptySet        = S []

setEmpty (S []) = True
setEmpty _      = False

inSet x (S xs)  = elem x (takeWhile (<= x) xs)

-- addSet adds only unique element
-- to set in ascending order,
-- hense set stays ordered without duplicates.
addSet x (S xs) = S (add x xs)
  where
    add x []                   = [x]
    add x s@(y:ys) | x > y     = y : (add x ys) 
                   | x < y     = x : s
                   | otherwise = s

-- delete element from set
delSet x (S xs) = S (del x xs)
  where
    del x []                   = []
    del x s@(y:ys) | x > y     = y : (del x ys)
                   | x < y     = s
                   | otherwise = ys


