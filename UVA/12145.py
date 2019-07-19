import sys


class pair:

    def __init__(self, first, second):
        self.first = first
        self.second = second

    def __mul__(self, o):
        return pair(self.first * o.first, max(self.second, o.second))

    def __add__(self, o):
        return pair(self.first + o.first, max(self.second, o.second))

    def __sub__(self, o):
        return pair(self.first-o.first, max(self.second, o.second))


def inp(s, b):
    i = s.find('=')
    if i > -1:
        return inp(s[:i], b)-inp(s[i+1:], b)
    i = s.find('+')
    if i > -1:
        return inp(s[:i], b)+inp(s[i+1:], b)
    i = s.find('*')
    if i > -1:
        return inp(s[:i], b)*inp(s[i+1:], b)
    return pair(int(s, b), len(s))


for line in sys.stdin:
    if line == '=':
        break
    b = 2
    for i in range(10, 2, -1):
        if str(i-1) in line:
            sys.stderr.write("{} {}\n".format(i, line[:-1]))
            b = i
            break
    l = []
    while b < 30:
        temp = inp(line[:-1], b)
        if (temp.first == 0):
            if temp.second == 1:
                l.append("{}+".format(b))
                break
            l.append(b)
        b += 1
    out = ""
    if len(l) == 0:
        print('*')
        continue
    if len(l) == 1:
        print(l[0])
        continue
    for i, e in enumerate(l):
        out += str(e)
        if (i + 1 < len(l)):
            out += ' '
    print(out)
