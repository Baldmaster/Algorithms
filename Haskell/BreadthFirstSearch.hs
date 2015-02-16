import Data.Array
import Data.Ix
import Queue

type Graph n w = Array n [(n,w)]

breadthFirstSearch :: Ix a => a -> Graph a b -> [a]
breadthFirstSearch start g = reverse (bfs (enqueue start emptyQueue) [])
  where
    bfs q visited
      | (isEmptyQueue q)         = visited
      | elem (front q) visited = bfs (dequeue q) visited
      | otherwise              = let c = front q
                                 in
                                   bfs (foldr enqueue (dequeue q) (adjacent g c)) (c:visited)

adjacent g v = map fst (g ! v)


graphAL = array (1,5) [(1, [(2,12),(3,34),(5,78)]),
                       (2, [(1,12), (4,55), (5,32)]),
                       (3, [(1,34), (4,61), (5,44)]),
                       (4, [(2,55), (3,61), (5,93)]),
                       (5,[(1,78),(2,32),(3,44),(4,93)])]

main = do
  print $ breadthFirstSearch 4 graphAL
