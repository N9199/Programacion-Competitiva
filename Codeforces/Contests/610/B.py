import sys


def debug(*args):
    print(*args, file=sys.stderr)


t = int(input())
for _ in range(t):
    n, p, k = list(map(int, input().split()))
    ai = list(map(int, input().split()))
    ai.sort()
    ai_accum = len(ai) * [0]
    for i in range(len(ai)):
        ai_accum[i] = ai_accum[i - 1] + ai[i] if i > 0 else ai[i]

    ans = 0
    for i in range(min(k, n)):
        if i > 0 and ai_accum[i-1] > p:
            break
        temp_ans = i
        temp_p = p - ai_accum[i - 1] if i > 0 else p

        for j in range(i+k-1, n, k):
            if ai[j] > temp_p:
                break
            temp_p -= ai[j]
            temp_ans += k
        ans = max(ans, temp_ans)
    print(ans)
