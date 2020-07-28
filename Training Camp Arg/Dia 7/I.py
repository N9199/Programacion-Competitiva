n = int(input())
l1 = list(map(int, input().replace('0', '').split()))
l2 = list(map(int, input().replace('0', '').split()))

i = 0
j = 0
ans = True
for k in range(n - 1):
    if l1[k] == 1:
        i = k
    if l2[k] == 1:
        j = k

for k in range(n):
    if l1[(i + k) % (n - 1)] != l2[(j + k) % (n - 1)]:
        ans = False
        break

if ans:
    print("YES")
else:
    print("NO")
    
