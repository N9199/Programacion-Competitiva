t = int(input())
for _ in range(t):
    n = int(input())
    k = 2
    while n % ((2**k) - 1) != 0:
        k += 1

    print(n//((2**k) - 1))
