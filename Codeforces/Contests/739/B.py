t = int(input())
for _ in range(t):
    a,b,c=list(map(int,input().split()))
    if a>b:
        a,b=b,a
    delta = b-a
    if delta*2<max(a,b,c):
        print(-1)
    else:
        if c<=delta:
            print(c+delta)
        else:
            print(c-delta)
