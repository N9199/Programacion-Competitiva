n = int(input())
li = list(map(int, input().split()))
i = 0
j = n - 1
l = 0
r = 0
a = 0
b = 0
while i < j:
    if l > r:
        r += li[j]
        b += 1
        j -= 1
    elif l < r:
        l += li[i]
        a += 1
        i += 1
    else:
        r += li[j]
        l += li[i]
        a += 1
        b += 1
        j -= 1
        i += 1
if i==j:
    if l > r:
        b += 1
    else:
        a+=1
    
if n == 1:
    a = 1
print(a,b)