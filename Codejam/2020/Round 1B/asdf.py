n = 5
l = n * [None]
l[0] = {(0, 0, '')}
for i in range(n-1):
    l[i+1] = set()
    for e in l[i]:
        l[i+1].add((e[0] + 2 ** i, e[1], e[2]+'E'))
        l[i+1].add((e[0] - 2 ** i, e[1], e[2]+'W'))
        l[i+1].add((e[0], e[1] + 2 ** i, e[2]+'N'))
        l[i+1].add((e[0], e[1] - 2 ** i, e[2]+'S'))

for e in l:
    e = list(filter(lambda x: x[0] >= 0 and x[1] >= 0, e))
    e.sort()
    print(e)
