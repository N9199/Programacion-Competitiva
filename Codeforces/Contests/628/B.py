t = int(input())
for _ in range(t):
    n = int(input())
    li = list(set(list(map(int, input().split()))))
    print(len(li))
    