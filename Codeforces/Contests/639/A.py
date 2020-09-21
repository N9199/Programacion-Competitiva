t = int(input())
for _ in range(t):
    n, m = list(map(int, input().split()))
    if n > m:
        n, m = m, n
    if n == 1:
        print("YES")
    elif n == 2 and m == 2:
        print("YES")
    else:
        print("NO")