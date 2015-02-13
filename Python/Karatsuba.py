"""
  Karatsuba multiplication.
 
"""
def karatsuba(x,y):
    if len(x) == 1 or len(y) == 1:
        return int(x) * int(y)
    else:
        while len(x)>len(y):
            y='0'+y
        while len(x)<len(y):
            x='0'+x
    
        [n, s] = (len(x) % 2 and [len(x) - 1,  1] or [len(x), 0])
    
        a = x[:(int(n/2) + s) ]
        b = x[ (int(n/2) + s):]
        c = y[:(int(n/2) + s) ]
        d = y[ (int(n/2) + s):]
       
        ac  = int(karatsuba(a,c))
        bd  = int(karatsuba(b,d))
        ab  = str(int(a)+int(b))
        cd  = str(int(c)+int(d))
        adbc= (karatsuba(ab,cd)) - ac - bd 
    

        return (10 ** n) * ac+(10 ** (n / 2)) * adbc + bd
