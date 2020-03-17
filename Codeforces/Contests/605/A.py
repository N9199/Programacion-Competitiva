t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    l.sort()
    if l[0] == l[1]:
        if l[1] == l[2]:
            ans = 0
        else:
            if l[1] == l[2] - 1:
                ans = 0
            else:
                ans = 2*(l[2] - l[1] - 2)
    elif l[1] == l[2]:
        if l[0] == l[1] - 1:
            ans = 0
        else:
            ans = 2*(l[1] - l[0] - 2)
    else:
        ans = (l[1]-l[0]-1)+(l[2]-l[1]-1)+(l[2]-l[0]-2)
    print(ans)
