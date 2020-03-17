def func(n: int, l: str, r: str):
    ans = ""
    m = {
        'a': 'b',
        'b': 'a',
        'c': 'a'
    }
    m1 = {'a': 'c', 'b': 'c'}
    if l == '0':
        l = 'a'
    ans += m[l]
    for i in range(1, n):
        ans += m[ans[i - 1]]
    assert(len(ans) == n)
    if ans[-1] == r:
        return ans[:-1] + m1[ans[-1]]
    return ans


n = int(input())

for _ in range(n):
    s = input().strip()

    flag = True
    for i in range(len(s) - 1):
        if s[i] == s[i + 1] and s[i] != '?':
            flag = False
            break
    ans = -1
    if flag:
        ans = ""
        j = -1
        for i in range(len(s)):
            if s[i] == '?':
                if j == -1:
                    j = i
                    ans += s[len(ans):i]

            elif j != -1:
                ans += func(i - j, s[j - 1] if j != 0 else '0', s[i])

                j = -1
        if j != -1:
            ans += s[len(ans):j]
            ans += func(len(s) - j, s[j - 1] if j != 0 else '0', '0')
        else:
            ans += s[len(ans):]

    print(ans)
