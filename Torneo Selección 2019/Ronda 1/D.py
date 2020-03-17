n, k = list(map(int, input().split()))
if k == 0:
    print(0)
else:
    f = (lambda x: x*(x+1)//2)
    ans = f(n)
    last = int(input())
    ans -= f(last-1)
    for _ in range(k - 1):
        temp = int(input())
        ans -= f(temp-1 - last)
        last = temp
    ans -= f(n-last)
    print(ans)
