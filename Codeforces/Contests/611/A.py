t = int(input())
for _ in range(t):
    h, m = list(map(int, input().split()))
    ans = 60 * (23 - h) + 60 - m
    print(ans)