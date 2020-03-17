n = int(input())
li = n * [-1]
for i in range(n):
    li[i] = int(input())
li.sort(reverse=True)
k = -1
ans = n*[0]
for i in range(n):
    ans[i] = min(i + 1, li[i])
print(max(ans))
