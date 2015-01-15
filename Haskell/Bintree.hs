-- Binary tree
--
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015
--

module BinTree (BinTree, emptyTree, inTree, addTree,
                delTree, buildTree, inOrder) where

inTree    :: (Ord a, Show a) => a -> BinTree a -> Bool
addTree   :: (Ord a, Show a) => a -> BinTree a -> BinTree a
delTree   :: (Ord a, Show a) => a -> BinTree a -> BinTree a
buildTree :: (Ord a, Show a) => [a] -> BinTree a
inOrder   :: (Ord a, Show a) =>  BinTree a -> [a]

data BinTree a = EmptyBT | NodeBT a (BinTree a) (BinTree a)
  deriving Show

emptyTree = EmptyBT

inTree v EmptyBT                          = False
inTree v (NodeBT x ltree rtree)  | v == x = True
                                 | v < x  = inTree v ltree
                                 | v > x  = inTree v rtree

addTree v EmptyBT                         = NodeBT v EmptyBT EmptyBT
addTree v (NodeBT x ltree rtree) | v == x = NodeBT x ltree rtree
                                 | v < x  = NodeBT x (addTree v ltree) rtree
                                 | v > x  = NodeBT x ltree (addTree v rtree)

buildTree [] = EmptyBT
buildTree xs = NodeBT x (buildTree left) (buildTree right)
  where right    = take n xs  -- if source list is sorted
        (x:left) = drop n xs  -- it is better to split it in two parts
        n = div (length xs) 2 -- in order to build almost balanced tree

inOrder EmptyBT                = []
inOrder (NodeBT v ltree rtree) = (inOrder ltree) ++ [v] ++ (inOrder rtree)

delTree v EmptyBT = EmptyBT
-- empty right subtree
delTree v (NodeBT x ltree EmptyBT)
  | v == x = ltree
-- empty left subtree
delTree v (NodeBT x EmptyBT rtree)
  | v == x = rtree
-- two subtrees exist             
delTree v (NodeBT x ltree rtree)
  | v < x     = NodeBT x (delTree v ltree) rtree
  | v > x     = NodeBT x ltree (delTree v rtree)
  | v == x    = let k = minTree rtree               -- get leftmost node in right subtree
                in NodeBT k ltree (delTree k rtree) -- then insert in place of 'v' and delete it from right subtree

-- looking for the leftmost node in right subtree
minTree (NodeBT v EmptyBT _) = v              -- No left subtree, that's it!
minTree (NodeBT _ ltree _ )  = minTree ltree  -- There is left subtree, so keep searching.
                                            

