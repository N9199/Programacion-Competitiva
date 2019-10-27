from math import factorial
n, r = list(map(int, input().split()))
ans = (factorial(n) // (factorial(r) * factorial(n - r)))
print(ans % 142857, ans % 27, ans % 11, ans % 13, ans % 37)
print(ans)
