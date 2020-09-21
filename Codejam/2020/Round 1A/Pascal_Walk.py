from math import sqrt
from sys import stderr
from queue import Queue

factorial = 1201*[1]
MOD = int(1e9) + 7


def inv(n):
    return pow(n, MOD-1, MOD)


def choose(n, k):
    assert(k <= n)
    return (factorial[n]*inv(k)*inv(n-k)) % MOD


def estimate(n):
    left, right = 1, 600-1
    while left < right:
        mid = (left + right+1) // 2
        if pow(16, mid) > (n**2)*(3*mid+1):
            right = mid-1
        else:
            left = mid
    return ((left+right+1)//2)//2


for i in range(1, 1201):
    factorial[i] = (factorial[i-1]*i) % (MOD)

t = int(input())
for _ in range(t):
    n = int(input())
    moves = 600 * [None]
    last = estimate(n)
    moves[0] = (2 * last, last)
    n -= choose(2 * last, last)
    i = 1
    while n > 0 and moves[i-1][0] > 0 and moves[i-1][1] > 0:
        t1 = pow(1 + moves[i-1][0], moves[i-1]
                 [1] - 1, MOD) + moves[i-1][0]
        t2 = pow(moves[i-1][0], moves[i-1]
                 [1] - 1, MOD) + moves[i-1][0] - 1
        if t1 >= n:
            moves[i] = (moves[i - 1][0] - 1, moves[i - 1][1] - 1)
            n -= t2
        else:
            moves[i] = (moves[i - 1][0], moves[i - 1][1] - 1)
            n -= t1
        i += 1
        print("n: {}".format(n), file=stderr)
    moves = moves[:i]
    print(moves)
