from math import gcd
n = int(input())

if n <= 2:
    ans = n
elif n % 2 == 1:
    ans = n * (n - 1) * (n - 2)
elif n % 3 == 0:
    ans = max((n * (n - 1) * (n - 3)) // 6,
              (n - 1) * (n - 2) * (n - 3))
else:
    ans = n*(n-1)*(n-3)

print(ans)
