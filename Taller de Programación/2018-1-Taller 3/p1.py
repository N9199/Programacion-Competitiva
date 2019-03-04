for asdfrghjk in [1]:
    n = int(input())
    l = []
    d = 100001
    k = input().split()
    for i in range(9):
        l.append(int(k[i]))
    for m in range(9):
        if l[m] <= d:
            d = l[m]
    p = n//d
    if p == 0:
        print(-1)
        break
    g = n - d*p
    resp = []
    for h in range(9):
        l[h] -= d
    for j in range(p):
        if l[8] <= g:
            resp.append(9)
            g -= l[8]
        elif l[7] <= g:
            resp.append(8)
            g -= l[7]
        elif l[6] <= g:
            resp.append(7)
            g -= l[6]
        elif l[5] <= g:
            resp.append(6)
            g -= l[5]
        elif l[4] <= g:
            resp.append(5)
            g -= l[4]
        elif l[3] <= g:
            resp.append(4)
            g -= l[3]
        elif l[2] <= g:
            resp.append(3)
            g -= l[2]
        elif l[1] <= g:
            resp.append(2)
            g -= l[1]
        elif l[0] <= g:
            resp.append(1)
            g -= l[0]
    fin = 0
    for w in range(p):
        fin += resp[w] * (10**(p-w-1))
    print(fin)
