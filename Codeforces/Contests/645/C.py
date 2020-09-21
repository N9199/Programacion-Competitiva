t = int(input())
for _ in range(t):
    x1, y1, x2, y2 = list(map(int, input().split()))
    delta_x = x2 - x1
    delta_y = y2 - y1
    if min(delta_x, delta_y) == 0:
        print(1)
    else:
        print((min(delta_x, delta_y))*max(delta_x, delta_y)+1)
