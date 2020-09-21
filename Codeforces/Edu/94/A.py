t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    ans = ''
    for i in range(0, 2 * n, 2):
        ans += s[i]
    print(ans)