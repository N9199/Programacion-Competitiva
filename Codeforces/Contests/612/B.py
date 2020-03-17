dp = 1501*[1501*[None]]


def choose(n, k):
    if k > n:
        return 0
    if dp[n][k] is not None:
        return dp[n][k]
    dp[n][k] = choose(n - 1, k) + choose(n-1, k-1)
    return dp[n][k]


n, k = list(map(int, input().split()))
li = n * [None]
for i in range(n):
    li[i] = input().strip()

choose(n, n)
ans = 0
for i in range(k):
    m = {}
    for s in li:
        if m.get(s[i], None) is None:
            m[s[i]] = 1
        else:
            m[s[i]] += 1
    for _, v in m.items():
        ans += choose(v, 3)

vals = list("SET")
invVals = {'S': 0, 'E': 1, 'T': 2}
s = {}
for e in li:
    m[e] = m.get(e, 0)+1

for key, v in s.items():
    temp = 0
    s1 = ""
    s2 = ""
    for i in range(k):
        s1 += vals[(invVals[key[i]] + 1) % 3]
        s1 += vals[(invVals[key[i]] + 2) % 3]
    
    ans += v*temp


print(ans)
