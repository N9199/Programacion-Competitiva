def isPal(n):
    n = str(n)
    for i in range(len(n)//2):
        if n[i] != n[-1-i]:
            return False
    return True


n = 924
m = 962

ans = n*m
i = 100
while i < 1000:
    j = 100
    while j < 1000:
        j += 1
        if isPal(i*j):
            temp = ans
            ans = max(ans, i*j)
            if temp != ans:
                print(i, j)
    i += 1

print(ans)
