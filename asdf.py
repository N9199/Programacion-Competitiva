import math


def create_matrix(n):
    m = []
    while len(m) < n or not check_temp(m):
        if len(m) == 0:
            m.append(n*[1])
            m.append(n*[1])
        if len(m) >= 2:
            l = len(m)*[0]
            while(not check_temp(m)):
                pass


def check_temp(m):
    if len(m) == 0:
        return False
    for i in range(len(m)):
        for j in range(i+1, len(m)):
            if dot_product(m[i], m[j]) != 0:
                return False
    return True


def dot_product(a, b):
    sum = 0
    for i in range(len(a)):
        sum += a[i]*b[i]
    return sum


size = int(input())-1
l = size*[[]]
for i in range(size):
    l[i].append(create_matrix(i+2))

for matrices in l:
    for matrix in matrices:
        print(matrix)
