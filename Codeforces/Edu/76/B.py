t = int(input())
for _ in range(t):
    x, y = list(map(int, input().split()))
    if x < 4 and y > 3:
        print("NO")
    elif x == 1 and y > 1:
        print("NO")
    else:
        print("YES")
