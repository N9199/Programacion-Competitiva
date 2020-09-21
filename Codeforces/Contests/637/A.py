t = int(input())
for _ in range(t):
    n, a, b, c, d = list(map(int, input().split()))

    if c-d <= n*(a+b) and c+d >= n*(a-b):
        print("Yes")
    else:
        print("No")
