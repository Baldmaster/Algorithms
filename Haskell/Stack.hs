module Stack(push, pop, top, emptyStack, stackEmpty) where

newtype Stack a = Stk [a] deriving Show
                      
push x (Stk xs)  = Stk (x:xs)

pop (Stk [])     = error "pop from an empty stack!"
pop (Stk (_:xs)) = Stk xs

top (Stk [])     = error "top from an empty stack!"
top (Stk (x:_))  = x

emptyStack       = Stk []

stackEmpty (Stk [])  = True
stackEmpty (Stk _ )  = False
