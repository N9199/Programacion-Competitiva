t = int(input())
for _ in range(t):
    a, b = list(map(int, input().split()))
    if a < b:
        a, b = b, a

    ans = -1
    for i in range(60):
        if b * (2 ** i) == a:
            ans = i // 3 + (i % 3 != 0)
            break
    print(ans)
