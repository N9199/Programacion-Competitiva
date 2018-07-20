from random import randint
n = 100000
m = 99999
print(n, m)
for i in range(1, m+1):
    print(i, i+1, randint(1e3, 1e6))
