t = int(input())
for _ in range(t):
    n = int(input())
    li = list(map(int, input().split()))
    li.sort()
    a, b = 0, 0
    c = 0
    for e in li:
        if a == e:
            a += 1
            continue
        if b == e:
            b += 1
    print(a+b)