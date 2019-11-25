t = int(input())
for _ in range(t):
    n, x, a, b = list(map(int, input().split()))
    if b < a:
        a, b = b, a
    print(min(n-1, b-a+x))
