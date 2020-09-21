n, m, L, R = list(map(int, input().split()))
temp = (n*m)*(n*m)
if n % 2 == 0 or m % 2 == 0 or (R-L) % 2 == 0:
    temp //= 2

print(temp % 998244353)
