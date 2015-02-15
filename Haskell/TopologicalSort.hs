import Data.Array

nodes g = indices g 

adjacent g v = map fst (g ! v)

inDegree g n = length [t | v <- nodes g, t <- adjacent g v, (n == t)]

topologicalSort :: Ix a => Array a [(a, b)] -> [a]
topologicalSort g = tsort [n | n <- nodes g , (inDegree g n == 0)] []
  where
    tsort [] r     = r
    tsort (c:cs) vis
      | elem c vis = tsort cs vis
      | otherwise  = tsort cs (c: (tsort (adjacent g c) vis))
