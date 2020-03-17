n = int(input())
d = {}
for _ in range(n):
    temp = int(input())
    if d.get(temp, None) is None:
        d[temp] = 1
    else:
        d[temp] += 1

d = [(key, value) for key, value in d.items()]
d.sort(reverse=True)
for i in range(1, len(d)):
    d[i] = (d[i][0], d[i][1]+d[i-1][1])

ans = 0

for k, v in d:
    ans = max(ans, min(k, v))


print(ans)
