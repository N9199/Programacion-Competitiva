n, s = list(map(int, input().split()))
if s - (n-1) > n:
    print("YES")
    print(' '.join((n-1) * ['1'] + [str(s - (n-1))]))
    print(n)
elif s - (n - 1) == n:
    print("NO")
    exit(0)
    # s=2n-1
    
else:
    print("NO")
