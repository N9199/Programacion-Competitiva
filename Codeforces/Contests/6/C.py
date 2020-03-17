r, c = list(map(int, input().split()))
n = r + c

if n == 2:
    print(0)
else:
    lr, lc = [], []
    a = 0
    for e in range(1, n + 1):
        if a < min(r, c)-1:
            lr.append(e)
            a += 1
        else:
            a = 0
            lc.append(e)
    if c < r:
        lr, lc = lc, lr

    for e1 in lr:
        s = ""
        li = [e1 * e for e in lc]
        for e in li:
            s += str(e) + ' '
        s.strip()
        print(s)
