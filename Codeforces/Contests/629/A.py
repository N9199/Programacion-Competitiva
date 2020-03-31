t = int(input())
for _ in range(t):
    a,b = list(map(int,input().split()))
    print((b-a%b)%b)