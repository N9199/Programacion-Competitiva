t = int(input())
for _ in range(t):
    trace = 0
    r = 0
    c = 0
    n = int(input())
    matrix = n*[None]
    for i in range(n):
        matrix[i] = list(map(int, input().split()))
        trace += matrix[i][i]
        temp = set(matrix[i])
        if len(temp) < len(matrix[i]):
            r += 1

    for i in range(n):
        temp = set()
        for j in range(n):
            temp.add(matrix[j][i])
        if len(temp) < n:
            c += 1

    print("Case #{}: {} {} {}".format(_+1, trace, r, c))
