from math import ceil
n, c = list(map(int, input().split()))
w = list(map(int, input().split()))
w.sort()

ans = 0
temp = 0

last = n - 1
for i in range(n):
    if i > last:
        break
    ans += 1
    temp = w[i]

    while temp <= c and i < last:
        temp += w[last]
        last -= 1

    if temp > w[i] and i < last:
        last += 1

print(ans)
