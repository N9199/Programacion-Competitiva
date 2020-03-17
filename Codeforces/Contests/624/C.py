import sys

t = int(input())
for _ in range(t):
    n, m = list(map(int, input().split()))
    s = input().strip()
    p = list(map(int, input().split()))

    delta = ord('a')
    ans = 26 * [0]
    accum = n * [None]
    for i in range(n):
        accum[i] = 26*[0]

    for i, c in enumerate(s):
        for j in range(26):
            accum[i][j] = accum[i - 1][j] if i > 0 else 0
        accum[i][ord(c) - delta] += 1

    for e in p:
        for j in range(26):
            ans[j] += accum[e - 1][j]
    for j in range(26):
        ans[j] += accum[-1][j]

    print(' '.join(map(str, ans)))
