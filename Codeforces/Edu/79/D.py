from math import gcd
import sys


def debug(*args):
    print(*args, file=sys.stderr)


def mod_inv(n: int):
    return pow(int(n), 998244352, 998244353)


n = int(input())
m = {}
ans = 0
ai = n * [None]
Kp = 2
for i in range(n):
    ai[i] = list(map(int, input().split()))
    k = ai[i].pop(0)
    ans += (k + 1)
    Kp *= k
    debug(ans)
    for e in ai[i]:
        if m.get(e, None) is None:
            m[e] = 1
        else:
            m[e] += 1
ans *= Kp*n

for i in range(n):
    for e in ai[i]:
        ans -= m[e] * (Kp // len(ai[i]))


print(ans)
print((ans*mod_inv(Kp*2*(n**2))) % 998244353)
