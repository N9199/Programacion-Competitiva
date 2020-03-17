t = int(input())
for _ in range(t):
    a, b, c, r = list(map(int, input().split()))
    if a > b:
        a, b = b, a
    print(b-a-max(min(b, c+r)-max(a, c-r), 0))
