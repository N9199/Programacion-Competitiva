n = int(input())
a = list(map(int, input().split()))
ans = n * [0]
m = 0
for i in range(n):
    ans[i] = a[i] + m
    m = max(m, ans[i])

print(" ".join(map(str, ans)))
