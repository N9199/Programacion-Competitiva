n, m = list(map(int, input().split()))
a = list(map(lambda x: ord(x) - ord('a'), input().strip()))
b = list(map(lambda x: ord(x) - ord('a'), input().strip()))

k = m * [0]
ans = m * [0]
for i in range(n-1, -1, -1):
    ans[m-n + i] = a[i]
for i in range(m - 1, n-1, -1):
    ans[i - n] = (b[i] - ans[i]) % 26

print(''.join(map(lambda x: chr(x+ord('a')), ans)))