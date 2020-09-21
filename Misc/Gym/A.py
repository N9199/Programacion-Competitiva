n = int(input())
for i in range(1, 10000):
    flag = False
    for j in range(2, 10000):
        if j * j > (n * i + 1):
            break
        if (n * i + 1) % j == 0:
            flag = True
            break
    if flag:
        print(i)
        break
