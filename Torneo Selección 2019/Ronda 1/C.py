import sys
lines = [line.strip() for line in sys.stdin.readlines()]
m = max(list(map(len, lines)))
print((m + 2) * "*")
i = 1
for line in lines:
    le = len(line)
    buff = (m - le) // 2
    if (m - le) % 2 != 0:
        i += 1
        i %= 2
    print("*" + (buff + ((m - le) % 2)*(i % 2)) * " " +
          line + (buff + ((m - le) % 2)*((i+1) % 2))*" " + "*")
print((m+2)*"*", end="")
