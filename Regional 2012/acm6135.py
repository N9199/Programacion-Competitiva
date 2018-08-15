import sys
"""TLE"""


def hasNextLine():
    """
    Return True if standard input has a next line. Otherwise return
    False.
    """
    global _buffer
    _buffer = sys.stdin.readline()
    if _buffer != '':
        return True
    else:
        if sys.hexversion < 0x03000000:
            _buffer = _buffer.decode('utf-8')
        if _buffer == '':
            return False
        return True


def simpsons_rule(f, a, b):
    c = (a+b) / 2.0
    h3 = abs(b-a) / 6.0
    return h3*(f(a) + 4.0*f(c) + f(b))


def asr(f, a, b, eps, whole):
    "Recursive implementation of adaptive Simpson's rule."
    c = (a+b) / 2.0
    left = simpsons_rule(f, a, c)
    right = simpsons_rule(f, c, b)
    if abs(left + right - whole) <= 15*eps:
        return left + right + (left + right - whole)/15.0
    return asr(f, a, c, eps/2, left) + asr(f, c, b, eps/2, right)


def adaptive_simpsons_rule(f, a, b, eps):
    "Calculate integral of f from a to b with max error of eps."
    return asr(f, a, b, eps, simpsons_rule(f, a, b))


def create_pol(l):
    def pol(x):
        ans = 0
        x_i = 1
        for c in l:
            ans += c*x_i
            x_i *= x
        return ans
    return pol


def create_rat(p, q):
    def rat(x):
        return p(x)/q(x)
    return rat


def func(f, d):
    def a(x):
        return max(f(x), -d)
    return a


_buffer = ''
while hasNextLine():
    w, d, a, k = list(map(int, _buffer.split(' ')))

    l = list(map(int, sys.stdin.readline().split(' ')))
    p = create_pol(l)
    l = list(map(int, sys.stdin.readline().split(' ')))
    q = create_pol(l)

    y1 = create_rat(p, q)

    l = list(map(int, sys.stdin.readline().split(' ')))
    p = create_pol(l)
    l = list(map(int, sys.stdin.readline().split(' ')))
    q = create_pol(l)

    y2 = create_rat(p, q)

    start = 0
    end = d
    for asdf in range(80):
        mid = (start+end)/2
        area1 = adaptive_simpsons_rule(func(y1, mid), 0, w, 1e-6)
        area2 = adaptive_simpsons_rule(func(y2, mid), 0, w, 1e-6)
        if area1-area2 > a:
            end = mid
        else:
            start = mid
    print("{:.5f}".format((start+end)/2))
