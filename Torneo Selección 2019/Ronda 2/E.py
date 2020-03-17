t = int(input())
for _ in range(t):
    s = input().strip()
    n = len(s)
    ans = 0
    for i in range(n - 1):
        if s[i] == s[i+1]:
            ans += (i + 1) * (n - i - 1) + i * (i + 1) // 2 + \
                (n - i - 2) * (n - i - 1) // 2
        else:
            ans += n
    print(ans)