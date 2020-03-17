from sys import stdin

d = set()
ans = set()

for line in stdin.readlines():
    d.update(line.rstrip().split())

for e1 in d:
    for e2 in d:
        if e1 != e2:
            ans.add(e1+e2)

for e in sorted(list(ans)):
    print(e)
