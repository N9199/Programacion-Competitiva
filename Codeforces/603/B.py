t = int(input())
for _ in range(t):
    n = int(input())
    l = [input() for i in range(n)]
    l2 = 10000*[0]
    s1 = set([int(e[0]) for e in l])
    s2 = set([int(e) for e in l])
    if len(s2) == n:
        print(0)
        for e in l:
            print(e)
    else:
        print(n - len(s2))
        for e in l:
            if l2[int(e)] == 0:
                print(e)
                l2[int(e)] += 1
            else:
                for i in range(10):
                    if i not in s1:
                        print(str(i)+e[1:])
                        s1.add(i)
                        break
