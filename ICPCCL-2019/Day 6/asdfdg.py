
from random import randint
from sys import stderr
n = randint(1, 5000)
m = randint(1, 5000)
c = randint(1, n)

s = "{} {} {}\n".format(n, m, c)
for i in range(m + 1):
    a, b = randint(1, n), randint(1, n)
    while a == b:
        print(a, b, file=stderr)
        a, b = randint(1, n), randint(1, n)
    s += "{} {}\n".format(a, b)

print(s, end='')
