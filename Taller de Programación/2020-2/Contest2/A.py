from sys import stderr
m = int(input())
for _ in range(m):
    n, T, a, b = list(map(int, input().split()))
    c = [a,b]
    ty = list(map(int, input().split()))
    ca = n - sum(ty)
    cb = n - ca
    time = list(map(int, input().split()))
    items = list(zip(time, ty))
    items.sort()
    ans = 0
    t = 0
    count = [0, 0]
    for i in range(n):
        if t > T:
            break
        if t < items[i][0]:
            temp = max(0, min(ca - count[0], (items[i][0] - 1 - t) // a))
            ans = max(ans, count[0] + count[1] + temp + max(0, min(cb - count[1], (items[i][0] - 1 - t - temp * a) // b)))
        count[items[i][1]] += 1
        t += c[items[i][1]]
    if t <= T:
        ans = n
    print(ans)