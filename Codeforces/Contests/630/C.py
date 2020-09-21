t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    s = input().strip()
    new_s = n*[None]
    m = k * [None]
    ans = 0
    for i in range(k):
        m[i] = {}
        for j in range(n // k):
            if m[i].get(s[i + k*j], None) is None:
                m[i][s[i + k*j]] = 1
            else:
                m[i][s[i + k * j]] += 1

    for i in range(k//2):
        for key, v in m[i].items():
            if m[k - 1 - i].get(key, None) is None:
                m[k - 1 - i][key] = m[i][key]
            else:
                m[k - 1 - i][key] += m[i][key]
        temp = (0, '')
        for key, v in m[k-1-i].items():
            temp = max(temp, (v, key))

        ans += 2*(n // k) - temp[0]

    if k % 2:
        temp = (0, '')
        for key, v in m[k // 2].items():
            temp = max(temp, (v, key))
        ans += (n//k) - temp[0]

    print(ans)
