r,c,a,b = list(map(int, input().split()))
li = r*[None]
for i in range(r):
    li[i]=c*[None]

A = a*[None]
B = b*[None]
for i in range(a):
    A[i] = int(input())
    if i >0:
        A[i]+=A[i-1]
for i in range(b):
    B[i] = int(input())
    if i >0:
        B[i]+=B[i-1]

ch = 1
d = {0:'W', 1:'B'}
invd = {'W':0,'B':1}
x=0
y=0

for j in range(r):
    li[j][0] = d[ch]
    if j+1 == A[x]:
        ch^=1
        x+=1
        x%=a

for i in range(r):
    ch = invd[li[i][0]]
    if 1 == B[y]:
        ch^=1
        y+=1
        y%=b
    for j in range(1,c):
        li[i][j] = d[ch]
        if j+1 == B[y]:
            ch^=1
            y+=1
            y%=b

for i in range(r):
    print(''.join(li[i]))