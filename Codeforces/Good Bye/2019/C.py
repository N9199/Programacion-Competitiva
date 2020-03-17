t = int(input())
for _ in range(t):
    n = int(input())
    prod, su = 0, 0
    ai = list(map(int, input().split()))
    for e in ai:
        prod ^= e
        su += e
    
    ans = [prod, prod + su]
    print(len(ans))
    print(*ans)