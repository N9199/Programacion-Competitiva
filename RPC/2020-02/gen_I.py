from random import randint, random
from math import pi, cos, sin, sqrt
from collections import namedtuple
from sys import stderr
import time


def debug(*x):
    print(*x, file=stderr, flush=True)


def dist(a, b):
    return (a.x-b.x)**2+(a.y-b.y)**2


n = randint(1, 1000)
m = randint(1, 10000)
k = randint(1, 1000)
print(n, m, k, flush=True)
circle = namedtuple('circle', 'x y r')
point = namedtuple('point', 'x y h')

redo = True
while redo:
    # debug("Start")
    accum = 0
    # debug("Make Islands")
    circles = n * [None]
    i = 0
    last = time.monotonic()
    while i < n:
        circles[i] = circle(randint(-1e6, 1e6),
                            randint(-1e6, 1e6),
                            randint(100, 1e5))
        # debug(circles[i])
        flag = (i == 0)
        while not flag and accum < 300:
            now = time.monotonic()
            accum += now - last
            last = now
            # debug("Accum: {}".format(accum))
            temp = True
            for j in range(i):
                if dist(circles[i], circles[j]) < (circles[i].r + circles[j].r) ** 2:
                    temp = False
                    break
                flag = temp
        if accum > 300:
            break
        if flag:
            i += 1
    if accum > 30:
        continue
    # debug("Make Trees")
    trees = m*[None]
    used = set()
    while len(used) < m:
        # debug(len(used))
        i = randint(0, n - 1)
        r = sqrt(random())
        theta = 2 * pi * random()
        (x, y) = (circles[i].x + int(r * circles[i].r * cos(theta)),
                  circles[i].y + int(r * circles[i].r * sin(theta)))

        while (x, y) in used:
            r = sqrt(random())
            theta = 2 * pi * random()
            (x, y) = (circles[i].x + int(r * circles[i].r * cos(theta)),
                      circles[i].y + int(r * circles[i].r * sin(theta)))
        trees[len(used)] = point(x, y, randint(1, 1e4))
        used.add((x, y))
    redo = False

for c in circles:
    print(c.x, c.y, c.r)

for p in trees:
    print(p.x, p.y, p.h)
