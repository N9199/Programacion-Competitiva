n = int(input().rstrip())
l = set()
for i in range(n):
    l.add(tuple(map(int, input().rstrip().split())))

w = list(map(int, input().rstrip().split()))

d = {0: (0, 0)}
s = ""
visited = set()
visited.add((0, 0))
for k in w:
    if d.get(k, None) is None:
        print("NO")
        exit(0)

    p = d[k]
    del d[k]
    s += "{} {}\n".format(*p)
    if p[1] == 0 and (p[0] + 1, p[1]) in l:
        visited.add((p[0] + 1, p[1]))
        d[-p[0] - 1] = (p[0] + 1, 0)
    else:
        if (p[0] + 1, p[1] - 1) in visited and (p[0]+1, p[1]) in l:
            visited.add((p[0] + 1, p[1]))
            d[p[1] - p[0] - 1] = (p[0] + 1, p[1])
    if p[0] == 0 and (0, p[1] + 1) in l:
        d[p[1] + 1] = (0, p[1] + 1)
        visited.add((0, p[1] + 1))
    else:
        if (p[0] - 1, p[1] + 1) in visited and (p[0], p[1] + 1) in l:
            visited.add((p[0], p[1] + 1))
            d[p[1]-p[0] + 1] = (p[0], p[1] + 1)

print("YES")
print(s, end="")
