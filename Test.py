import random
def f(n,k):
    l = n*[0]
    a = True
    while(not test(l) or a):
        a = False
        for i in range(n):
            l[i]= random.randint(1,k)
    return l

def test(l):
    for i in reversed(range(2,max(l))):
        a = True
        try:
            j = l.index(i)
        except:
            return False
        
        while(a and j>=0):
            if l[j]==i-1:
                a = False
            else:
                j-=1
        if a:
            return False
    return True

print(f(10,3))
