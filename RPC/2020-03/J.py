n = int(input())
M, *l = list(map(int, input().split()))
l.sort(reverse=True)
ans = l[0] - l[1]
if M < l[0]:
    print(0)
elif n == 3:
    print(ans + 2 * (M - l[0]))
else:
    if M - 1 <= l[2] + 2 * (M - l[0] - 1) + ans:
        print(ans + 2 * (M - l[0]) - 1)
    else:
        print(ans + 2 * (M - l[0]))
