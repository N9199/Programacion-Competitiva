from sys import setrecursionlimit

setrecursionlimit(int(2e7))

MOD = int(1e9)+7
p = 7

ini = [[1 for _ in range(p)] for __ in range(p)]
for i in range(1,p):
    for j in range(1, p):
        ini[i][j] = (ini[i][j - 1] + ini[i - 1][j]) % p
        
blocks = [[[0 for _ in range(p)] for __ in range(p)] for ___ in range(2)]
blocks[1] = ini
for x in range(p):
    for y in range(p):
        blocks[1][x][y] = int(blocks[1][x][y] != 0)


blocks3 = [21, 49-21]
        

print(blocks3)

def biggest(n, p):
    ans = 1
    e = 0
    while n > ans:
        ans *= p
        e += 1
    return (ans, e)


memo = [[-1 for i in range(p)] for j in range(30)]
def full(e, t, p):
    if memo[e][t] != -1:
        return memo[e][t]
    ans = 0
    if t == 0:
        return pow(p, 2*e, MOD)
    if e == 1:
        return blocks3[0]
    for i in range(2):
        ans += blocks3[i]*full(e-1, i, p)
        ans %= MOD
    memo[e][t] = ans
    return memo[e][t]

def func(n, t, p):
    if n == 0:
        return 0
    if t!=0 and n == 1:
        return 0
    po, e = biggest(n, p)

    temp = n // (po // p)
    temp2 = n % (po // p)

    if t == 0:
        return (((n+1)*n)//2)%MOD
    ans = 0
    if n < p:
        for i in range(n):
            for j in range(i + 1):
                ans += (blocks[1][i][j]==0)
        ans%=MOD
        return ans
    for i in range(temp - 2):
        for j in range(temp - 2 - i):
            ans += full(e, blocks[t][i][j], p)
            ans %= MOD


    ans += (temp + 1) * func(temp2, 1, p)
    ans %= MOD
    ans += (full(e - 1, 1, p) - temp2 * (temp2 + 1) // 2)
    ans %= MOD

    return ans
