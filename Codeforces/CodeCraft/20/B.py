t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(lambda x: ord(x)-ord('a'), input().strip()))
    s2 = sorted(list(set(s)))
    print(s, s2)
    i = 0
    j = 1
    if len(s2) == 1:
        pass
    else:
        possible = []
        for i, e in enumerate(s):
            if e == s2[0]:
                possible.append(i + 1)
        
        

    