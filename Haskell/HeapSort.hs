-- Heapsort
-- using priority queue. See Pqueue.h
--
-- Skupoy Sergey. sergey.archlinux@gmail.com
import Pqueue

makePQ :: (Ord a) => [a] -> PQueue a
makePQ = foldr enqueuePQ emptyPQ

heapSort :: (Ord a) => [a] -> [a]
heapSort xs = heapSort' (makePQ xs)
  where heapSort' pq
         | isEmptyPQ pq = []
         | otherwise    = frontPQ pq : heapSort' $ dequeuePQ pq
