a, b = list(map(int, input().split()))
ans = 0
while a > b:
    if a % 2:
        a += 1
        ans += 1
    a //= 2
    ans += 1
print(b-a+ans)
