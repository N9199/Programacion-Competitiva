s = input().rstrip()
d = list(map(int, list(input().rstrip())))
d.sort()
d = d[::-1]


i = 0
ans = ""
for j in range(len(s)):
    if i < len(d) and int(s[j]) < d[i]:
        ans += str(d[i])
        i += 1
    else:
        ans += s[j]

print(ans)
