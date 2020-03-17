import sys


def debug(*args):
    print(*args, file=sys.stderr)


t = int(input())
for _ in range(t):
    m, n = list(map(int, input().split()))
    an = list(map(int, input().split()))
    bm = list(map(int, input().split()))
    bm_set = set(bm)
    seen = set()
    ans = 0
    i = 0
    j = 0
    while len(bm) > 0:
        temp = bm.pop(0)
        if temp in seen:
            ans += 1
            j += 1
        while temp not in seen:
            if temp == an[i]:
                ans += 2 * (i - j) + 1
                j += 1
                seen.add(temp)
            elif an[i] in bm_set:
                seen.add(an[i])
            i += 1
    print(ans)
