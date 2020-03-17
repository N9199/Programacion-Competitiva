from math import cos, sin, radians

l, w, h = list(map(int, input().split()))
x, y, a = list(map(int, input().split()))

if 0-h/101 <= x + h*cos(radians(a)) <= w + h/101 and 0-h/101 <= y + h*sin(radians(a)) <= l + h/101:
    print("YES")
else:
    print("NO")
