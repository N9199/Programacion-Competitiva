t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input()))
    c = list(map(int,input()))
    g = n*[None]
    for i in range(n):
        g[i] = []
    