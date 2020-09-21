n = int(input())
li = n * [None]
m = {}
c = 0
for i in range(n):
    li[i] = input().strip()
    if li[i] not in m:
        m[li[i]] = (li[i][0], 0)
    m[li[i]] = (m[li[i]][0], m[li[i]][1] + 1)
temp = list(m.values())
temp.sort()
temp.append(('1', 0))

ans = 0
j = 0
i = 0
while i < len(temp)-1:
    c = 0
    while temp[i][0] == temp[j][0] and j < len(temp)-1:
        c += temp[j][1]
        j += 1
    while i < j:
        ans += (c - temp[i][1]) * temp[i][1]
        i += 1

print(ans)
    