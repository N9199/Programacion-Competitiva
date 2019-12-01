from sys import stdin
from math import log, ceil
li = [(0, int(x)) for x in stdin.readlines()]
it = ceil(log(max([x[1] for x in li]), 3))
for _ in range(it):
    li = [
        (x[0] + max(0, x[1] // 3 - 2), max(0, x[1] // 3 - 2))
        for x in li
    ]
    if _ == 0:
        print(sum([x[0] for x in li]))
print(sum([x[0] for x in li]))