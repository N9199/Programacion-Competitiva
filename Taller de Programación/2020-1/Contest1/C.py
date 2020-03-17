k = int(input())
for _ in range(k):
    n = int(input())
    li = list(map(int, input().split()))
    li.sort(reverse=True)
    k = -1
    ans = n*[0]
    for i in range(n):
        ans[i] = min(i + 1, li[i])
    print(max(ans))
