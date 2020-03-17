t = int(input())
for _ in range(t):
    a, b = list(map(int, input().split()))
    if a < b:
        print(1 if (b-a) % 2 else 2)
    elif b < a:
        print(2 if (a-b) % 2 else 1)
    else:
        print(0)
