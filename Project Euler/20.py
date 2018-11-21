from math import factorial

n = 100
sum = 0
for k in str(factorial(n)):
    sum += int(k)

print(sum)