t = int(input())
for _ in range(t):
    n, x, y = list(map(int, input().split()))
    if x < y:
        x, y = y, x
    li = n * [0]
    temp_d = 1
    temp = int(1e9)+1
    for d in range(n - 1, 0, -1):
        if (x - y) % d == 0:
            a = (x - y) // d

            if y % a > 0:
                c = y % a
            else:
                c = (y % a) + a

            b = (x - c) // a
            if b >= n - 1:
                temp_d = d
                temp = x
                break
            elif temp > c + a * (n - 1):
                temp_d = d
                temp = c + a * (n - 1)
    if temp == int(1e9) + 1:
        a = x - y
        if y % a > 0:
            temp = (y % a) + a * (n - 1)
        else:
            temp = a + (y % a) + a * (n - 1)
    a = (x - y) // temp_d
    li[0] = temp
    flag1 = li[0] != x
    flag2 = True
    for i in range(1, n):
        li[i] = li[i - 1] - a
        """ if flag1 and li[i] == x:
            flag1 = False
        if flag2 and li[i] == y:
            flag2 = False """
    print(' '.join(map(str, li)))
    assert (li[-1] > 0)
    """ 
    assert (not flag1)
    assert (not flag2) """
