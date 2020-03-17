t = int(input())
for _ in range(t):
    a, b, c, r = list(map(int, input().split()))
    if b < a:
        a, b = b, a
    ans = 0
    if c < a:
        if c + r < a:
            ans = b - a
        else:
            ans = max(b - (c + r), 0)
    elif c > b:
        if c - r > b:
            ans = b - a
        else:
            ans = max((c - r) - a, 0)
    else:
        ans += max(0, b - (c + r)) + max(0, c - r - a)
    print(ans)
