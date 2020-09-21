t = int(input())
for _ in range(t):
    n = int(input())
    e = list(map(int, input().split()))
    ans = 0
    e.sort()
    temp = 0
    c = e[0]
    for i in range(n):
        temp += 1
        if e[i] != c:
            c = e[i]
        if temp == c:
            ans += 1
            temp = 0
    print(ans)
