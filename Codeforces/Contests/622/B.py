t = int(input())
for _ in range(t):
    n, x, y = list(map(int, input().split()))
    a = 1
    b = n
    if x > y:
        x, y = y, x
    l, r = 1, n
    while l < r:
        m = (r + l) // 2
        # x-(m-1) y-(m-1) n-(m-1):
        if n-x > y-m:
            r = m
        else:
            l = m+1
    a = (l + r) // 2
    l, r = 1, n
    while l < r:
        m = (l + r+1) // 2
        if n - (n - x + 1) > (n - y + 1) - m:
            r = m-1
        else:
            l = m
    b = n + 1 - (l+r)//2

    print(a, b)
