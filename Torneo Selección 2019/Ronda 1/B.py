s = input().strip()
if len(s) % 2 != 0:
    print(-1)
else:
    d = {
        'L': 0,
        'R': 0,
        'U': 0,
        'D': 0
    }
    for c in s:
        if d.get(c, None) is None:
            d[c] = 1
        else:
            d[c] += 1

    print((abs(d['R']-d['L'])+abs(d['U']-d['D']))//2)
