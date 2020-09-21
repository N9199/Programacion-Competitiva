n,m=list(map(int, input().split()))
g = [[0 for i in range(n)] for j in range(n)]
for _ in range(m):
    u, v = list(map(int, input().split()))
    u -= 1
    v -= 1
    g[u][v] += 1
    g[v][u] += 1

print(',\n'.join(map(lambda x: ','.join(map(str,x)), g)))