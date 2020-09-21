t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    count = 1
    ans = 1
    i = 0
    for j in range(n):
        if a[j] <= count + j - i:
            ans = max(count + j - i+1, ans)
    print(ans)
