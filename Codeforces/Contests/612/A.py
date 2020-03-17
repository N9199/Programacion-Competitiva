t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input().strip())
    ans = 0
    marked = []
    for i in range(n):
        if s[i] == 'A':
            marked.append(i)
    s.append('A')
    flag = True
    while flag:
        ans += 1
        flag = False
        for i in marked:
            if s[min(i + ans, n)] == 'P':
                s[min(i + ans, n)] = 'A'
                flag = True
            
    print(ans-1)
