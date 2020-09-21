t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    b = (n//2)*[None]
    for i in range(n // 2):
        b[i] = a[i] + a[-(i + 1)]

    ans = 0
    d = {}
    d2 = {}
    d3 = {}
    for i in range(n // 2):
        if d.get(b[i], None) is None:
            d[b[i]] = 1
        else:
            d[b[i]] += 1
        if d2.get(a[i]+1, None) is None:
            d2[a[i]+1] = 1
        else:
            d2[a[i]+1] += 1
        if d3.get(a[-(i+1)]+1, None) is None:
            d3[a[-(i+1)]+1] = 1
        else:
            d3[a[-(i+1)]+1] += 1

    d = list(d.items())
    d.sort(key=lambda x: (x[1], -x[0]))
    d2 = list(d2.items())
    d2.sort(key=lambda x: (x[1], -x[0]))
    d3 = list(d3.items())
    d3.sort(key=lambda x: (x[1], -x[0]))
    temp = d[0][0]
    for i in range(n // 2):
        if b[i] != temp:
            if (temp - k > a[i] and temp - k > a[-(i + 1)]):
                ans += 2
            else:
                ans += 1
    ans1 = 0
    temp = d2[0][0]
    for i in range(n // 2):
        if b[i] != temp:
            if (temp - k > a[i] and temp - k > a[-(i + 1)]):
                ans1 += 2
            else:
                ans1 += 1
    ans2 = 0
    temp = d3[0][0]
    for i in range(n // 2):
        if b[i] != temp:
            if (temp - k > a[i] and temp - k > a[-(i + 1)]):
                ans2 += 2
            else:
                ans2 += 1

    print(min(ans, ans1, ans2))
    #print(b, a, sep='\n')
