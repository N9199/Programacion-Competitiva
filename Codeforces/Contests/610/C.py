import sys


def debug(*args):
    print(*args, file=sys.stderr)


m = int(input())
for _ in range(m):
    n, T, a, b = list(map(int, input().split()))
    l1 = list(map(lambda x: a if x == '0' else b, input().split()))
    l2 = list(map(int, input().split()))
    li = list(zip(l2, l1))
    li.sort()
    le = list(filter(lambda x: x[1] == a, li))
    lh = list(filter(lambda x: x[1] == b, li))

    ans = 0
    time = 0
    for i, e in enumerate(li):
        if time + e[1] > e[0]:
            break
        temp_ans = i+1
        time += e[1]
        left, right = 0, len(le) - 1
        while left < right:
            mid = (left + right) // 2
            if le[mid][0] > time:
                right = mid
            else:
                left = mid + 1
        mid = (left+right)//2
        extra_le = min(len(le)-1 - mid, (e[0] - time) // a)
        extra_lh = 0
        if time + extra_le * a < e[0]:
            left, right = 0, len(lh) - 1
            while left < right:
                mid = (left + right) // 2
                if lh[mid][0] > time + extra_le * a:
                    right = mid
                else:
                    left = mid + 1
            mid = (left+right)//2
            extra_lh = min(len(lh)-1-mid, (e[0]-time-extra_le*a)//b)
        ans = max(ans, temp_ans+extra_le+extra_lh)
    print(ans)
