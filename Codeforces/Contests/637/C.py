t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    m = 1
    c = n * [1]
    right = list(range(n))
    flag = True
    queue = n * [None]
    for i in range(n):
        queue[i] = (p[i], i)
    queue.sort()
    for i in range(n):
        if c[q[i][1]] >= m:
            right[g[i][1]] = right[g[i][1] + 1] if g[i][1] + 1 < n else n
            if right[g[i][1]] < n:
                c[right[g[i][1]]] += c[g[i][1]]
                m = max(m, c[right[g[i][1]]])
            c[g[i][1]] = 0
        else:
            flag = False
            break
    
    if flag:
        print("Yes")
    else:
        print("No")