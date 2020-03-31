t = int(input())
for _ in range(t):
    n,k = list(map(int, input().split()))
    if n%2!=k%2:
        print("NO")
    elif (2*k+1)*k-k*(k+1)>n:
        print("NO")
    else:
        print("YES")