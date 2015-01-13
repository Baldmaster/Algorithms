-- Selection sort.
--
-- Skupoy Sergey.  sergey.archlinux@gmail.com, 2015
--

split [] m r     = m : (ssort r)
split (x:xs) m r = case x < m of
                       True  -> split xs x (m:r)
                       False -> split xs m (x:r)

ssort []     = []
ssort (x:xs) = split xs x []
