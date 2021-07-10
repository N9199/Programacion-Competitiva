n,x = list(map(int, input().split()))
h = list(map(int, input().split()))
m = 1
c = 1
for i in range(n-1):
    if x>= h[i+1]-h[i]:
        c += 1
    else:

        m = max(c,m)
        c=1
m = max(c,m)
print(m)