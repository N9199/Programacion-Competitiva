t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = list(set(a))
    left = n * [None]
    for i in range(n):
        left[i] = {}
    for e in s:
        left[0][e] = 1 if a[0] == e else 0
    for i in range(1, n):
        for e in s:
            left[i][e] = 1 if a[i] == e else 0
            left[i][e] += left[i - 1][e]

    flag = True
    for i in range(1, n - 1):
        if not flag:
            break
        for e in s:
            if left[-1][e]-left[i][e] > 0 and left[i - 1][e] > 0:
                print("YES")
                flag = False
                break
    if flag:
        print("NO")
