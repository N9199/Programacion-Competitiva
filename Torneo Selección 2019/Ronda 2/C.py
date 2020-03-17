import sys

for line in sys.stdin.readlines():
    r, c = list(map(int, line.replace('R', "").split('C')))
    if r == 0 and c == 0:
        break
    s = ""
    while c > 0:
        c -= 1
        s = chr(ord('A') + c % 26) + s
        c //= 26

    print(s+str(r))
