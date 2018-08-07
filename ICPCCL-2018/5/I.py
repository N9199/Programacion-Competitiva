import sys

flag = True
array = []
n = 0
for line in sys.stdin:
    if flag:
        n = int(line)
        flag = False
    