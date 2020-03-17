t = int(input())
for _ in range(t):
    a, b, p = list(map(int, input().split()))
    s = input().strip()

    m = {'A': a, 'B': b}
    temp = {(len(s)-1, m[s[-2]])}
    for i in reversed(range(len(s)-1)):
        if s[i] != s[i + 1]:
            temp.add((i+1, m[s[i]]))

    temp = list(temp)
    temp.sort(reverse=True)
    flag = True
    for e in temp:
        #print(p, e)
        if p < e[1]:
            print(e[0]+1)
            flag = False
            break
        else:
            p -= e[1]
    if flag:
        print(1)
