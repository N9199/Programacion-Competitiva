t = int(input())
for _ in range(t):
    n = int(input())
    ans1 = 0
    ans2 = 2**n
    for i in range(n // 2):
        ans1 += 2 ** (n - i - 1)
    for i in range(n // 2 - 1):
        ans2 += 2**(i+1)
    print(abs(ans1-ans2))
