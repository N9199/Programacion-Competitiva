from sys import stderr, setrecursionlimit

x = int(4e8)
setrecursionlimit(x)
m = {
    "1110111": 0,
    "0010010": 1,
    "1011101": 2,
    "1011011": 3,
    "0111010": 4,
    "1101011": 5,
    "1101111": 6,
    "1010010": 7,
    "1111111": 8,
    "1111011": 9
}


def diff(s, t):
    ans = 0
    for i in range(7):
        if s[i] < t[i]:
            ans += 1
        elif s[i] > t[i]:
            return - 1
    return ans


def debug(*arg):
    print(*arg, file=stderr, flush=True)


dp = []
d = []
n, k = 0, 0


def func(i, left):
    if i == n:
        return 0 if left == 0 else - int('1' + 2000 * '0')
    if dp[i][left] is not None:
        return dp[i][left]
    ans = -int('1'+2000*'0')
    for key, value in m.items():
        temp = diff(d[i], key)

        if temp != -1 and temp <= left:
            ans = max(ans, value*(10**(n-i-1))+func(i+1, left-temp))
    dp[i][left] = ans
    return ans


n, k = list(map(int, input().split()))
dp = n * [None]
for i in range(n):
    dp[i] = (k+1)*[None]

d = n * [None]
for i in range(n):
    d[i] = input().strip()

temp = func(0, k)
if temp < 0:
    print(-1)
else:
    print(temp)
