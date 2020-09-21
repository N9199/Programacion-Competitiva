from functools import reduce
t = int(input())
for _ in range(t):
    n = int(input())
    li = list(map(int, input().split()))
    li.sort()
    
    ans = reduce(lambda a, b: a * b, li[:5])
    ans = max(reduce(lambda a, b: a * b, li[:4]+li[-1:]), ans)
    ans = max(reduce(lambda a, b: a * b, li[:3]+li[-2:]), ans)
    ans = max(reduce(lambda a, b: a * b, li[:2]+li[-3:]), ans)
    ans = max(reduce(lambda a, b: a * b, li[:1]+li[-4:]), ans)
    ans = max(reduce(lambda a, b: a * b, li[:0]+li[-5:]), ans)
    print(ans)
