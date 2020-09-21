t = int(input())
for _ in range(t):
    n = int(input())

    def f(x): return ((3 * (x + 1) * x) // 2) - x

    ans = 0
    while n > 1:
        left, right = 1, int(1e5)
        while left < right:
            mid = (left + right + 1) // 2
            if f(mid) > n:
                right = mid - 1
            else:
                left = mid

        n -= f((left+right + 1)//2)
        ans += 1
    print(ans)
