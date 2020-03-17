t = int(input())
for _ in range(t):
    li = list(map(int, input().split()))
    m = max(li)
    s = sum(li)
    if m > s - m + 1:
        print("No")
    else:
        print("Yes")