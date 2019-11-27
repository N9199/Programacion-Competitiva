from math import gcd, ceil
t = int(input())
for _ in range(t):
    r, b, k = list(map(int, input().split()))
    r, b = r//gcd(b, r), b//gcd(b, r)
    if ceil((max(b, r)-1)/min(b, r)) >= k:
        print("REBEL")
    else:
        print("OBEY")
