from sys import stderr


def debug(*x):
    return
    print(*x, file=stderr, flush=True)


def sign(x):
    if x > 0:
        return 1
    elif x < 0:
        return - 1
    else:
        return 0


t = int(input())
for _ in range(t):
    x, y = list(map(int, input().split()))
    x_bin, y_bin = bin(abs(x))[2:], bin(abs(y))[2:]
    ans = ""
    debug("Hola")
    m_h = {-1: 'W', 1: 'E'}
    m_v = {-1: 'S', 1: 'N'}
    if (abs(x) + abs(y)) % 2 == 1 or abs(x) + abs(y) == 0:
        i = 0
        while abs(x) + abs(y) >= 2 ** i:
            i += 1
        i -= 1
        while abs(x) + abs(y) > 0:
            debug("(x,y): {},{}".format(x, y))
            if abs(x) > abs(y):
                ans = m_h[sign(x)] + ans
                x -= sign(x) * (2 ** i)
            else:
                ans = m_v[sign(y)] + ans
                y -= sign(y) * (2 ** i)
            i -= 1
    else:
        ans = "IMPOSSIBLE"

    print("Case #{}: {}".format(_+1, ans))
