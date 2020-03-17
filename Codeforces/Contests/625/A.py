n = int(input())
r = list(map(int, input().split()))
b = list(map(int, input().split()))
rs = sum(r)
bs = sum(b)
a = sum([e1 * (1 - e2) for e1, e2 in zip(r, b)])
c = sum([(1-e1) * e2 for e1, e2 in zip(r, b)])
if rs > bs:
    print(1)
elif bs >= rs and a > 0:
    #bs-rs < k*(a-1)
    print((bs - rs)//a+2)
else:
    print(-1)
