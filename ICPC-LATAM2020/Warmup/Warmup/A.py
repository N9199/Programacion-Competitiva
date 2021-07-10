n = int(input())
L = list(map(int,input().split()))
accum = set()
s = 0
for e in L:
    s+=e
    accum.add(s)

if s%2:
    print('N')

c=0
for e in accum:
    if e+s//2 in accum:
        c+=1

if c>=2:
    print('Y')
else:
    print('N')