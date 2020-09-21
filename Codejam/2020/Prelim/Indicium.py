t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    flag = True
    ans = n * [None]
    for i in range(n):
        ans[i] = n * [None]
    temp = k
    for i in range(n):
        ans[i][i] = min(max(temp+i+1-n, 1), n)
        temp -= ans[i][i]
    m = {True: "POSSIBLE", False: "IMPOSSIBLE"}
    print("Case #{}: {}".format(_ + 1, m[flag]))
    if flag:
        print('\n'.join(map(lambda x: ' '.join(map(str, x)), ans)))
