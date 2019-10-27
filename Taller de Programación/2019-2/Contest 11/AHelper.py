def h(n, m):
    if n % m != 0:
        return n
    return h(n//m, m)


n, m = list(map(int, input().split()))
l = [h(i, m) for i in range(1, n + 1)]  # F list

ans = 1
for e in l:
    ans *= e

print(ans % 27)
l = [i if i % 3 != 0 else 1 for i in range(1, 28)]  # f list
print(l)
for i in range(1, len(l)):
    l[i] = (l[i] * l[i - 1]) % 27
print(l[n])
print(l)
