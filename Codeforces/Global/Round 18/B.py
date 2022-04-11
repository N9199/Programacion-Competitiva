from math import floor, log2

def f(n,i):
    ans = 0
    while n>0 and n>=2**i:
        l = floor(log2(n+1))
        ans += (2**l)//2
        n-=2**l
    return ans

t = int(input())
for _ in range(t):
    l,r =list(map(int, input().split()))
    curr = 0
    p = 2
    for i in range(18):
        temp1 = f(r,i)
        temp2 = f(l-1,i)
        curr = max(curr, temp1-temp2)
    print()
    print(r-l+1-curr)