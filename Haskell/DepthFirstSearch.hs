import Data.Array
import Data.Ix
import Stack

type Graph n w = Array n [(n,w)]

depthFirstSearch :: Ix a => a -> Graph a b -> [a]
depthFirstSearch start g = reverse (dfs (push start emptyStack) [])
  where
    dfs s vis
      | (stackEmpty s)   = vis
      | elem (top s) vis = dfs (pop s) vis
      | otherwise        = let c = top s
                           in
                             dfs (foldr push (pop s) (adjacent g c)) (c:vis)

adjacent g v = map fst (g ! v)


graphAL = array (1,5) [(1, [(2,12),(3,34),(5,78)]),
                       (2, [(1,12), (4,55), (5,32)]),
                       (3, [(1,34), (4,61), (5,44)]),
                       (4, [(2,55), (3,61), (5,93)]),
                       (5,[(1,78),(2,32),(3,44),(4,93)])]

main = do
  print $ depthFirstSearch 4 graphAL
