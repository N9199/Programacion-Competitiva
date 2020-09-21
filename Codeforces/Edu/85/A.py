t = int(input())
for _ in range(t):
    n = int(input())
    p, c = 0, 0
    flag = True
    for i in range(n):
        a, b = list(map(int, input().split()))
        if a < b or a < p or b < c or a - b < p - c:
            flag = False
        p, c = a, b
    m = {True: "YES", False: "NO"}
    print(m[flag])
