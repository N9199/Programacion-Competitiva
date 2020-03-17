from math import sqrt

h, l = list(map(int, input().split()))

print("{0:10.13f}".format(-(h**2-l**2)/(2*h)))
