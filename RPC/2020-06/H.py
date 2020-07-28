n = int(input())
t = list(map(int, input().split()))
d = -1
te = 50

for i in range(n - 2):
    if te > max(t[i], t[i + 2]):
        d = i + 1
        te = max(t[i], t[i + 2])
print(d, te)

