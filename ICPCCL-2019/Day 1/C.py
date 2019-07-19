from math import log, floor
a, b = input().rstrip().split()
m = max(len(a), len(b))
if a + b == "00":
    print(1)
    exit(0)
for i in reversed(range(1, 10)):
    if str(i) in a + b:
        if ((i + 1) ** m <= int(a, i + 1) + int(b, i + 1)):
            print(m+1)
        else:
            print(m)
        break
