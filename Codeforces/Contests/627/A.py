t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = max(a)
    flag = True
    for e in a:
        if e % 2 != b % 2:
            print("NO")
            flag = False
            break
    if flag:
        print("YES")