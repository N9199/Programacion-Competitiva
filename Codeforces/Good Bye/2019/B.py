t = int(input())
for _ in range(t):
    n = int(input())
    ai = list(map(int, input().split()))
    flag = True
    for i in range(n - 1):
        if abs(ai[i] - ai[i + 1]) >= 2:
            print("YES")
            print(i+1, i + 2)
            flag = False
            break
    if flag:
        print("NO")