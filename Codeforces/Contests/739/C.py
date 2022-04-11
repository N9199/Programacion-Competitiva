t = int(input())
for _ in range(t):
    k = int(input())
    if k==1:
        print(1,1)
        continue
    left=0
    right=int(1e5)
    while left<right:
        mid = (left+right+1)//2
        if k>=mid**2:
            left = mid
        else:
            right = mid-1
    n = left
    if k==n**2:
        r=n
        c=1
    elif k<n**2+n+1:
        r=k-n**2
        c=n+1
    else:
        r=n+1
        c=(n+1)**2-k+1
    print(r,c)
    
