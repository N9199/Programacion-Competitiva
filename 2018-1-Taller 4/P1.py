n = int(input())
m = {}
l = []
c = 0
for i in range(n):
    s = input().split(' ')
    if m.get(s[2].lower(), None) is None:
        l.append(1)
        m[s[2].lower()] = c
        c += 1

    if m.get(s[0].lower(), None) is None:
        l.append(l[m[s[2].lower()]] + 1)
        m[s[0].lower()] = c
        c += 1
    else:
        l[m[s[0].lower()]] += 1

t = 0
for item in l:
    t = max(item, t)

print(t)
