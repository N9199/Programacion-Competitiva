def sign(x):
    if x > 0:
        return 1
    elif x < 0:
        return - 1
    return 0


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if a[0] != b[0]:
        print("NO")
        continue

    min_a = min(a)
    max_a = max(a)
    if min_a >= 0 and min(b) < 0:
        print("NO")
        continue

    if max_a <= 0 and max(b) > 0:
        print("NO")
        continue

    flag = True
    flag2 = True
    accum = n * [(False, False)]
    if a[0] == b[0] and a[0] != 0:
        if a[0] == -1:
            accum[0] = (False, True)
        if a[0] == 1:
            accum[0] = (True, False)

    for i in range(1, n):
        accum[i] = list(accum[i-1])
        if not accum[i][0]:
            if a[i] == b[i]:
                if a[i] == 1:
                    accum[i][0] = True
            elif accum[i][1]:
                if a[i] == 1:
                    accum[i][0] = True
        if not accum[i][1]:
            if a[i] == b[i]:
                if a[i] == -1:
                    accum[i][1] = True
            elif accum[i][0]:
                if a[i] == -1:
                    accum[i][1] = True

    m = {-1: 1, 1: 0}
    for i in range(1, n):
        if a[i] != b[i] and not ((sign(b[i]) == 0 and (accum[i-1][m[-sign(a[i])]] or accum[i-1][m[-sign(a[i])]])) or (sign(b[i]) and accum[i-1][m[sign(b[i])]])):
            flag2 = False
            break

    if flag2:
        flag = False

    if flag:
        print("NO")
        continue

    print("YES")
