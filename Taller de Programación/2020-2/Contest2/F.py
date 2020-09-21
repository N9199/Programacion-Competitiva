import os
n, m, k = list(map(int, input().split()))
a = list(map(int, input().split()))
a.append(0)
for i in range(n, 0, -1):
    a[i] -= a[i - 1]
q = m * [None]
for i in range(m):
    q[i] = list(map(int, input().split()))

queries = (m+1) * [0]

for _ in range(k):
    x, y = list(map(int, input().split()))
    queries[x - 1] += 1
    queries[y] -= 1


for i in range(1, m):
    queries[i] += queries[i - 1]

for i in range(m):
    a[q[i][0] - 1] += queries[i] * q[i][2]
    a[q[i][1]] -= queries[i] * q[i][2]

for i in range(1, n):
    a[i] += a[i - 1]

out = ' '.join(map(str, a[:n]))
out = out.encode(encoding='UTF-8')
os.write(1, out)
