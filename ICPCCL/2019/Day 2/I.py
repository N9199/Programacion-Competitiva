import sys
DP = dict()


def f(n):
    if (n < 3):
        return n
    if (n in DP):
        return DP[n]
    DP[n] = max(n, f(n//2) + f(n//3) + f(n//4))
    return DP[n]


for line in sys.stdin:
    n = int(line.rstrip())
    print(f(n))
