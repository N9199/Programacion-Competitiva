import math
import numpy as np


def create_matrix(n):
    a = np.ones((n, n), dtype=float)
    temp = 1.0/math.sqrt(n)
    a *= temp
    temp2 = 2**(n**2)
    b = a.transpose()
    c1 = 0
    with open("output.txt", mode='w') as f:
        while not np.array_equal(a.dot(b), np.identity(n)):
            f.write(str(c1)+'\n')
            i = 0
            while a[i % n, i // n] != temp:
                a[i % n, i // n] = temp
                i += 1
            a[i % n, i // n] = -temp
            c1 += 1
            b = a.transpose()
            if c1 >= temp2:
                return

    return a


def mult(num, place):
    if (num >> place) % 2:
        return True
    return False


def lprint(p):
    n = 0
    for i in range(len(p)):
        n += p[i]*2**i
    return n

print(create_matrix(8))