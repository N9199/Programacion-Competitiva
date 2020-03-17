from math import gcd

t = int(input())
for _ in range(t):
    x = int(input())
    if x == 2:
        print(1, 1)
    elif x % 2:
        print(1, x - 1)
    else:
        print(2, x-2)
