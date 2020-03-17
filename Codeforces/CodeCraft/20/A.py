t = int(input())
for _ in range(t):
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    s = sum(a)
    ans = min(s, m)
    print(ans)

