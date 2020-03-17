t = int(input())
for _ in range(t):
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    p = set(map(int, input().split()))
    for __ in range(len(a)):
        for i in range(len(a)-1):
            if a[i] > a[i + 1] and i+1 in p:
                a[i], a[i + 1] = a[i + 1], a[i]
    flag = True
    for i in range(len(a)-1):
        if a[i] > a[i + 1]:
            print("NO")
            flag = False
            break
    if flag:
        print("YES")
