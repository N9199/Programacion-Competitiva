import sys


def Format(s, t):
    a = [None]*(t-1)
    total = 0
    j = len(s)-1
    for i in reversed(range(len(s))):
        pass


n = int(sys.stdin.readline())
t = 1
header = ""
lines = ""
lastline = ""
out = ""

for line in sys.stdin.readlines():
    if len(lastline) > 0:
        out += header + '\n'
        out += lines
        out += lastline + '\n'
        header = lines = lastline = " "
    if len(header) == 0:
        temp = ""
        j = 0
        for i in range(len(line)):
            if (line[i] == 'P' or line[i] == 'T') and i != 0:
                temp += line[j:i] + ' '
                j = i
                t += 1
        temp += line[j:-1]
        header += temp
    else:
        if line[0:2] == "TP":
            lastline = line[0:2]+' '+Format(line[3:], t)

print(out)
