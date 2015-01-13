-- Priority queue
--
-- Skupoy Sergey. sergey.archlinux@gmail.com, 2015
--

module Pqueue (PQueue, emptyPQ, isEmptyPQ, enqueuePQ, dequeuePQ, frontPQ) where

emptyPQ   :: PQueue a
isEmptyPQ :: PQueue a -> Bool
enqueuePQ :: (Ord a) => a -> PQueue a -> PQueue a
dequeuePQ :: (Ord a) => PQueue a -> PQueue a
frontPQ   :: (Ord a) => PQueue a -> a

newtype PQueue a = PQ [a]

isEmptyPQ (PQ [])   = True
isEmptyPQ _         = False

emptyPQ             = PQ []

enqueuePQ x (PQ q)  = PQ (insert x q)
    where insert x []                   = [x]
          insert x r@(y:ys) | x <= y    = x:r
                            | otherwise = y : insert x ys

dequeuePQ (PQ [])     = error "PQ dequeue error: empty queue!"
dequeuePQ (PQ (x:xs)) = PQ xs

frontPQ (PQ [])       = error "PQ front error: empty queue!"
frontPQ (PQ (x:xs))   = x

instance (Show a) => Show (PQueue a) where
  showsPrec p (PQ (queue)) str
    = showString "PQ " (showList (queue) str)


