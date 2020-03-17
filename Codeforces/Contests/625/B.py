n = int(input())
b = list(map(int, input().split()))
temp = 0
ans = 0
path = [e for e in b]
max_a = n * [0]
min_a = n*[0]
for i in reversed(range(n)):
    max_a[i] = max(b[i], max_a[i + 1]) if i < n - 1 else b[i]
    min_a[i] = min(b[i], min_a[i + 1]) if i < n - 1 else b[i]

for i in reversed(range(n)):
    if max_a[i] > b[i]:
        for j in range(1, n - i):
            if b[i + j] - b[i] == j:
                path[i] += path[i+j]
                break
            if max_a[i + j] <= b[i] or min_a[i+j]-j > b[i]:
                break
print(max(path))
