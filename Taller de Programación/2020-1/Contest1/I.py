from sys import stdin, stderr


nw = {}
wn = {}
op = {'-': -1, '+': 1}
for line in stdin.readlines():
    line = line.strip().split()
    if line[0] == "def":
        line[2] = int(line[2])
        nw[wn.get(line[1], None)] = None
        wn[line[1]] = line[2]
        nw[line[2]] = line[1]
    elif line[0] == "calc":
        ans = 0
        line = [line[0]] + ['+'] + line[1:]
        for i in range(2, len(line), 2):
            temp = wn.get(line[i], None)
            if temp is None:
                ans = None
                break
            else:
                ans += op[line[i - 1]] * temp
        ans = nw.get(ans, None)
        if ans is None:
            ans = "unknown"
        line.append(ans)
        print(' '.join(line[2:]))
    else:
        nw.clear()
        wn.clear()
