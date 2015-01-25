module Queue(Queue, enqueue, dequeue, emptyQueue, front) where

newtype Queue a = Q ([a], [a])

isEmptyQueue (Q ([], [])) = True
isEmptyQueue _            = False

emptyQueue                = Q ([], [])

enqueue x (Q ([], []))    = Q ([x], [])
enqueue y (Q (xs, ys))    = Q (xs, y:ys)

dequeue (Q ([], []))      = error "Error dequeue. Empty queue!"
dequeue (Q ([], xs))      = Q (tail (reverse xs), [])
dequeue (Q (x:xs, ys))    = Q (xs, ys)

front (Q ([], []))        = error "front: empty queue!"
front (Q ([], ys))        = last ys
front (Q (x:xs, ys))      = x

instance (Show a) => Show (Queue a) where
  showsPrec p (Q (front, rear)) str
    = showString "Q " (showList (front ++ reverse rear) str)
