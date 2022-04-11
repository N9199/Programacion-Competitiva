t = int(input())
for _ in range(t):
    n,m,k=list(map(int,input().split()))
    n2=n-n%2
    m2=m-m%2
    if k%2==0:
        if n%2:
            if (m//2)%2==0 and k>= m//2 and (m2*n2)//2>=k-(m//2):
                print("YES")
            else:
                print("NO")
        elif (m2*n2)//2>=k:
            print("YES")
        else:
            print("NO")
    else:
        if n%2 and (m//2)%2 and (m2*n2)//2>=k-(m//2) and k>=(m//2):
            print("YES")
        else:
            print("NO")