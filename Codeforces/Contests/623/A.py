t = int(input())
for _ in range(t):
    a, b, x, y = list(map(int, input().split()))
    print(max(a*y, a*(b-y-1), x*b, (a-x-1)*b))
