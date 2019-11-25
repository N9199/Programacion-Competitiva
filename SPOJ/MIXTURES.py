# Brute Force
def func(l: list):
    if (len(l) == 1):
        return l[0]
    ans = (1e9, 1)
    for i in range(len(l) - 1):
        temp = func(
            l[:i] + [(l[i][1] * l[i + 1][1]+l[i][0]+l[i+1][0], (l[i][1] + l[i + 1][1]) % 100)] + l[i + 2:])
        if ans[0] > temp[0]:
            ans = temp
    return ans


n = int(input())
mixtures = list(map(lambda x: (0, int(x)), input().split()))
print(mixtures)
print(func(mixtures))
