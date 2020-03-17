import sys


def debug(*args):
    print(*args, file=sys.stderr)


t = int(input())
for _ in range(t):
    n, s = list(map(int, input().split()))
    a = list(map(int, input().split()))
    accum = n * [0]
    m_accum = n * [int(1e9)]
    flag = True
    for i in range(n):
        accum[i] = accum[i - 1] + a[i] if i > 0 else a[i]
        if i > 0:
            if a[i] > m_accum[i - 1][0]:
                m_accum[i] = (a[i], i)
            else:
                m_accum[i] = m_accum[i - 1]
        else:
            m_accum[i] = (a[i], i)
        if flag and accum[i] - m_accum[i][0] > s:
            print(m_accum[i-1][1] + 1)
            flag = False

    if flag and accum[-1] > s:
        print(m_accum[-1][1] + 1)
        flag = False

    if flag:
        print(0)

