t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print(-1)
    elif n % 3 == 1:
        print((n-2)*"2"+"33")
    else:
        print((n - 1) * "2" + "3")
