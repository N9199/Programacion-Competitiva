t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    l.sort()
    a = sum(l)
    l[2] -= a % 2
    a = a - a % 2
    l.sort()
    a -= l[2]
    if l[2] > a:
        print(a)
    else:
        print((a + l[2]) // 2)
