t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    l.sort(reverse=True)
    ans = 0
    n = 1
    while n < 8 and l[0]+l[1]+l[2] > 0:
        flag = True
        for i in range(3):
            if n & (2 ** i) and not l[i]:
                flag = False
                break
        for i in range(3):
            if flag and (n & (2**i)):
                l[i] -= 1
        if flag:
            ans += 1

        n += 1

    print(ans)
