t = int(input())
for _ in range(t):
    a, b = list(map(int, input().split()))
    if (a + b) % 3 == 0 and abs(a-b) <= min(a, b):
        print("Yes")
    else:
        print("No")
