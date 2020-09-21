t = int(input())
for _ in range(t):
    n = int(input())
    events = (2*n)*[None]
    for i in range(n):
        temp = list(map(int, input().split()))
        events[2*i] = (temp[0], "s", i)
        events[2*i+1] = (temp[1], "e", i)
    events.sort()
    curr = 0
    used = 2*[-1]
    flag = True
    ans = n*[""]
    for e in events:
        if e[1] == "e":
            if used[curr] == e[2]:
                used[curr] = -1
            elif used[curr ^ 1] == e[2]:
                used[curr ^ 1] = -1
        else:
            if used[curr] >= 0:
                curr ^= 1
            if used[curr] >= 0:
                flag = False
                break
            used[curr] = e[2]
            ans[e[2]] = curr*"C"+(1-curr)*"J"
    if flag:
        ans = ''.join(ans)
    else:
        ans = "IMPOSSIBLE"
    print("Case #{}: {}".format(_+1, ans))
