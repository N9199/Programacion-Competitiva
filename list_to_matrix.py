n, m = list(map(int, input().split()))
g = n * [None]
for i in range(n):
    g[i] = n * ['0']

for _ in range(m):
    u, v = list(map(int, input().split()))
    u -= 1
    v -= 1
    g[u][v] = '1'
    g[v][u] = '1'

print('\n'.join([', '.join(e) for e in g]))
