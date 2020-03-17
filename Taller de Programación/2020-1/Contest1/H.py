from sys import setrecursionlimit
s = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
m = {}
for i in range(len(s)):
    for j in range(len(s[i])):
        m[s[i][j]] = (i, j)


def dist(a):
    a, b = a
    if len(a) > 1:
        return sum(list(map(dist, zip(a, b))))
    return abs(m[a][0] - m[b][0]) + abs(m[a][1] - m[b][1])


CALETA = int(2e6)
setrecursionlimit(CALETA)
t = int(input())
for _ in range(t):
    s, l = input().strip().split()
    s = s.strip()
    l = int(l)
    li = l * [None]
    for i in range(l):
        li[i] = input().strip()

    li.sort(key=lambda x: (dist((s, x)), x))
    for e in li:
        print(e, dist((e, s)))
