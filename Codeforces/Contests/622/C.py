n = int(input())
l = list(map(int, input().split()))
l2 = [(e, i) for i, e in enumerate(l)]
l2.sort(reverse=True)

if l2[-1][0] == l2[0][0]:
    print(' '.join(map(str, l)))
    exit(0)

m = 0
for e in l2:
    if e[0] == l2[0][0]:
        m += 1

l4 = n * [0]
for e in l2:
    l3 = n * [0]
    l3[e[1]] = e[0]
    for i in reversed(range(e[1])):
        l3[i] = min(l3[i + 1], l[i])
    for i in range(e[1] + 1, n):
        l3[i] = min(l3[i - 1], l[i])
    if sum(l4) < sum(l3):
        l4 = l3
print(' '.join(map(str, l4)))
