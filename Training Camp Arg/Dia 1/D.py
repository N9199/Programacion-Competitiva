n, a, b = map(int, input().split())
c = 0
li = list(map(int, input().split()))
ans = 0
for i in range(n):
    if li[i] == 2:
        if b > 0:
            b -= 1
        else:
            ans += 2
    else:
        if a > 0:
            a -= 1
        elif b > 0:
            b -= 1
            c += 1
        elif c > 0:
            c -= 1
        else:
            ans += 1
print(ans)
        
