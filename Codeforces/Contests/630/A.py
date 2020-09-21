t = int(input())
for _ in range(t):
    a, b, c, d = list(map(int, input().split()))
    x, y, x1, y1, x2, y2 = list(map(int, input().split()))
    flag1 = abs(a - b) <= x2 - x1
    flag2 = abs(c - d) <= y2 - y1

    if (a > 0 or b > 0) and x2 == x1:
        flag1 = False
    if (c > 0 or d > 0) and y2 == y1:
        flag2 = False

    if a > b:
        flag1 = flag1 and a - b <= x-x1
    elif b > a:
        flag1 = flag1 and b - a <= x2 - x
    else:
        flag1 = flag1 and abs(a-b) <= max(x2-x, x-x1)

    if c > d:
        flag2 = flag2 and c - d <= y-y1
    elif d > c:
        flag2 = flag2 and d - c <= y2 - y
    else:
        flag2 = flag2 and abs(c-d) <= max(y2-y, y-y1)

    if flag1 and flag2:
        print("Yes")
    else:
        print("No")
