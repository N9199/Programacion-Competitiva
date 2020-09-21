t = int(input())
for _ in range(t):
    d = {'+': 1, '-': -1}
    li = list(map(lambda x: d[x], input().strip()))
    accum = len(li) * [0]
    for i in range(len(li)):
        accum[i] += li[i]
        if i > 0:
            accum[i] += accum[i - 1]
    ans = 0
    m = len(li)
    for i in range(len(li)):
        if accum[i] < 0:
            if m > 0:
                ans += (i + 1) * (-accum[i])
            else:
                ans += (i+1)*(max(0, m-accum[i]))
        m = min(accum[i], m)
    print(ans+len(li))
    
