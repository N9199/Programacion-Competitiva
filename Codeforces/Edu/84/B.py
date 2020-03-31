from sys import stderr

t = int(input())
for _ in range(t):
    n = int(input())
    s = set()
    p = n*[False]
    for i in range(n):
        g = list(map(int, input().split()))
        k = g[0]
        g = g[1:]
        for e in g:
            if e not in s:
                p[i] = True
                s.add(e)
                break
    
    flag = True
    for e in p:
        flag = flag and e
    if flag:
        print("OPTIMAL")
    else:
        print("IMPROVE")

        for i in range(n):
            if not p[i]:
                for j in range(n):
                    if j+1 not in s:
                        print(i+1,j+1)
                        break
                break