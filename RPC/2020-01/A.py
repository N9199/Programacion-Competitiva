n, d = list(map(int, input().split()))
l = n*[None]
for i in range(n):
    l[i] = int(input())

s = sum(l)
l = list(map(lambda x: str(d // s * x), l))
print('\n'.join(l))