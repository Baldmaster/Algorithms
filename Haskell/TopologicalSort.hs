import Data.Array

nodes :: Ix i => Array i e -> [i]
nodes g = indices g 

adjacent :: Ix i => Array i [(a, b)] -> i -> [a]
adjacent g v = map fst (g ! v)

inDegree :: (Ix i, Eq a) => Array i [(a, b)] -> a -> Int
inDegree g n = length [t | v <- nodes g, t <- adjacent g v, (n == t)]

topologicalSort :: Ix a => Array a [(a, b)] -> [a]
topologicalSort g = tsort [n | n <- nodes g , (inDegree g n == 0)] []
  where
    tsort [] r     = r
    tsort (c:cs) vis
      | elem c vis = tsort cs vis
      | otherwise  = tsort cs (c: (tsort (adjacent g c) vis))
