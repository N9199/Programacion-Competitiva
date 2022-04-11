t = int(input())
for _ in range(t):
    n = int(input())
    s = sum(map(int, input().split()))
    if s%n==0:
        print(0)
    else:
        print(1)