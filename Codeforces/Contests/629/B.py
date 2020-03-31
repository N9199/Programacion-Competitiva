from math import sqrt

t = int(input())
for _ in range(t):
    n,k = list(map(int, input().split()))
    x = int(sqrt(k))
    while (x-2)*(x-1)//2<k:
        x+=1
    x-=1
    ans = n*["a"]
    ans[-x]="b"
    k-=(x-2)*(x-1)//2

    ans[-k]='b' 
    print(''.join(ans)) 