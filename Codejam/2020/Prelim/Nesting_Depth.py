t = int(input())
for _ in range(t):
    s = list(map(int, input().strip()))
    ans = ""
    last = 0
    for i in range(len(s)):
        if last < s[i]:
            ans += (s[i] - last) * "(" + str(s[i])
        elif s[i] < last:
            ans += (last - s[i]) * ")" + str(s[i])
        else:
            ans += str(s[i])
        last = s[i]
    if last > 0:
        ans += last*")"
    print("Case #{}: {}".format(_+1, ans))
