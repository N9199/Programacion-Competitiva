from sys import stderr


def debug(*args):
    print(*args, file=stderr, flush=True)


t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    s = list(input().strip())
    s.sort()

    if k == 1:
        print(''.join(s))
    else:
        ans = ''
        for i in range(k - 1, n, k):
            if s[0] == s[i]:
                ans += s[0]
            else:
                break
        if s[k-1] != s[0]:
            ans = s[k-1]
        else:
            temp_i = i
            while i >= 0 and s[i] != s[0]:
                i -= 1
            i += 1
            if len(set(s)) > 2:
                ans += ''.join(s[i:])
            elif i != temp_i:
                ans += s[i]
                debug("Hi", ans)
            else:
                for j in range(i, n, k):
                    ans += s[j]
                if j != n-1:
                    ans += s[-1]
                debug("N", ans)

        print(ans)
