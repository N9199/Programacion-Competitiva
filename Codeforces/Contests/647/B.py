t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(int, input().split()))
    s.sort()
    m = dict(map(lambda x: (x[1], x[0]), enumerate(s)))
    temp = n*[0]
    flag = True
    for i in range(1, n):
        k = s[0] ^ s[i]
        flag2 = True
        for e in s:
            if e ^ k in m:
                if temp[m[e ^ k]] != -1:
                    temp[m[e ^ k]] = 1
                else:
                    flag2 = False
                    break
            else:
                flag2 = False
                break
        if flag2:
            print(k)
            flag = False
            break
    if flag:
        print(-1)
