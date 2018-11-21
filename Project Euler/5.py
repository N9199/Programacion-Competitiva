from math import gcd

temp = 1
for n in range(1, 21):
    temp = temp*n//gcd(temp, n)

print(temp)
