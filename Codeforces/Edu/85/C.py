t = int(input())
for _ in range(t):
    n = int(input())
    m = n*[None]
    for i in range(n):
        m[i] = list(map(int, input().split()))

    accum = n * [None]
    for i in range(n):
        accum[i] = [(i + 1) % n, max(0, m[(i + 1) % n][0] - m[i][1])]

    ans = 0
    temp_ans = m[0][0]
    for i in range(n-1):
        temp_ans += accum[i][1]
    ans = temp_ans
    for i in range(1, n):
        temp_ans += accum[(i - 2 + n) % n][1]
        temp_ans -= accum[i-1][1]
        temp_ans -= m[i - 1][0]
        temp_ans += m[i][0]
        ans = min(temp_ans, ans)
    print(ans)
