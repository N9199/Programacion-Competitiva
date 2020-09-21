t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    accum = n * [0]
    for i in range(1, n-1):
        if a[i] > a[i + 1] and a[i] > a[i - 1]:
            accum[i] += 1
        accum[i] += accum[i-1]
    accum[-1] += accum[-2]
    l = 0
    ans = 0
    for i in range(k - 1, n):

        if accum[i-1] - accum[i-k+1] > ans:
            ans = accum[i-1] - accum[i-k+1]
            l = i-k+1

    print(ans+1, l+1)

