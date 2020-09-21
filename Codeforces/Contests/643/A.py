from sys import stderr
t = int(input())
for _ in range(t):
    a, k = list(map(int, input().split()))
    c = 1
    last = 0
    while last != a and c < k:
        c += 1
        last = a
        a += min(list(map(int, list(str(a))))) * max(list(map(int, list(str(a)))))

    print(a)
