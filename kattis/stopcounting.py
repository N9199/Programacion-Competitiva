n = int(input())
a = list(map(int, input().split()))
accum = (n+2)*[0]
for i in range(n):
    accum[i+1] = a[i]+accum[i]

ans = 0
for i in range(1, n+1):
    ans = max(ans, accum[i]/i, (accum[n] - accum[n - i])/i)

print(f"{ans:.9f}")
