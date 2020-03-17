t = int(input())
for _ in range(t):
    s = input().strip()
    d = 1
    ans = 0
    for i in reversed(range(len(s))):
        if s[i] == 'R':
            ans = max(ans, d)
            d = 1
        else:
            d += 1
    ans = max(ans, d)
    print(ans)