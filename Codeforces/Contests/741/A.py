t = int(input())
for _ in range(t):
    l, r = list(map(int, input().split()))
    if r // 2 >= l:
        print((r+1) // 2 - 1)
    else:
        print((r-l+1)//2)
