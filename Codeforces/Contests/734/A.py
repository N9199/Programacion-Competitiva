t = int(input())
for _ in range(t):
    n = int(input())
    if n%3==0:
        print(n//3, n//3)
    elif n%3==1:
        print(n//3+1,n//3)
    else:
        print(n//3,n//3+1)