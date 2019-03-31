from random import shuffle, randint
n = int(input())
a = 6e7
l = [randint(-a, a) for i in range(n)]

ps = []
i = 0
while i < 2**n:
    temp = 0
    for j in range(n):
        if (i >> j) % 2 == 1:
            temp += l[j]
    i += 1
    ps.append(temp)

shuffle(ps)

print(n)
for e in ps:
    print(e)
