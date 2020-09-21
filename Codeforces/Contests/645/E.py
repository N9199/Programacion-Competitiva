from math import floor, ceil
n = int(input())
first = ceil(n/2)
second = floor(n / 2)
a = list(map(int, input().split()))
x = int(input())
if sum(a) + second * x <= 0:
    print(-1)
else:
    print(first+second)
