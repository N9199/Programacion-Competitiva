t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    flag = a[0] > 0
    ans = 0
    i = 0
    for j in range(n):
        if flag:
            if a[j] < 0:
                ans += a[i]
                flag = not flag
                i = j
            else:
                if a[j] > a[i]:
                    i = j
        else:
            if a[j] > 0:
                ans += a[i]
                flag = not flag
                i = j
            else:
                if a[j] > a[i]:
                    i = j
    ans += a[i]
    print(ans)
                