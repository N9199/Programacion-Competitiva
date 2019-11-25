input()
l = list(map(int, list(input().rstrip().split())))
l.sort()
if l[-1] == l[0]:
    print(0, (len(l) * (len(l) - 1)) // 2)
    exit(0)

n = k = 0
for e in l:
    if l[0] == e:
        n += 1
    else:
        break


for e in reversed(l):
    if l[-1] == e:
        k += 1
    else:
        break


print(l[-1]-l[0], n*k)
