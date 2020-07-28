n, x, y, c = list(map(int, input().split()))
left, right = 0, 2 * n+1
while left < right:
    mid = (left + right) // 2

    temp = 2 * mid * (mid + 1) + 1
    a = [mid - (n - x), mid - (y - 1), mid - (x - 1), mid - (n - y)]
    a = list(map(lambda x: max(0, x), a))
    for e in a:
        temp -= pow(e, 2)
    for i in range(4):
        temp += min(a[i], a[(i + 1) % 4]) * (min(a[i], a[(i + 1) % 4]) + 1) // 2
    if temp >= c:
        right = mid
    else:
        left = mid + 1

print((left + right) // 2)
mid = (left + right) // 2
temp = 2 * mid * (mid + 1) + 1
a = [mid - (n - x), mid - (y - 1), mid - (x - 1), mid - (n - y)]
a = list(map(lambda x: max(0, x), a))
for e in a:
    temp -= pow(e, 2)
for i in range(4):
    temp += min(a[i], a[(i + 1) % 4]) * (min(a[i], a[(i + 1) % 4]) + 1) // 2
assert(temp>=c)