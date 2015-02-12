adjacent g v = map fst (g ! v)

inDegree g n = length [t | v<-nodes g, t<-adjacent g v, (n == t)]

topologicalSort g = tsort [n | n<-nodes g , (inDegree g n == 0)] []
  where
    tsort [] r
    tsort (c:cs) vis
      | elem c vis = tsort cs vis
      | otherwise  = tsort cs (c: (tsort (adjacent g c) vis))
