inMap = {
    ("xxxxx"
     "x...x"
     "x...x"
     "x...x"
     "x...x"
     "x...x"
     "xxxxx"): 0,
    ("....x"
     "....x"
     "....x"
     "....x"
     "....x"
     "....x"
     "....x"): 1,
    ("xxxxx"
     "....x"
     "....x"
     "xxxxx"
     "x...."
     "x...."
     "xxxxx"): 2,
    ("xxxxx"
     "....x"
     "....x"
     "xxxxx"
     "....x"
     "....x"
     "xxxxx"): 3,
    ("x...x"
     "x...x"
     "x...x"
     "xxxxx"
     "....x"
     "....x"
     "....x"): 4,
    ("xxxxx"
     "x...."
     "x...."
     "xxxxx"
     "....x"
     "....x"
     "xxxxx"): 5,
    ("xxxxx"
     "x...."
     "x...."
     "xxxxx"
     "x...x"
     "x...x"
     "xxxxx"): 6,
    ("xxxxx"
     "....x"
     "....x"
     "....x"
     "....x"
     "....x"
     "....x"): 7,
    ("xxxxx"
     "x...x"
     "x...x"
     "xxxxx"
     "x...x"
     "x...x"
     "xxxxx"): 8,
    ("xxxxx"
     "x...x"
     "x...x"
     "xxxxx"
     "....x"
     "....x"
     "xxxxx"): 9,
    ("....."
     "..x.."
     "..x.."
     "xxxxx"
     "..x.."
     "..x.."
     "....."): '+'
}
outMap = {}
for k, i in inMap.items():
    outMap[i] = k

temp = input().rstrip()
l = ((len(temp) // 6)+1) * [""]

j = 0
for i, c in enumerate(temp):
    if (i+1) % 6 == 0:
        j += 1
        continue
    l[j] += c


for i in range(6):
    temp = input().rstrip()
    j = 0
    for i, c in enumerate(temp):
        if (i+1) % 6 == 0:
            j += 1
            continue
        l[j] += c

a = 0
b = 0
flag = True
for e in l:
    if inMap[e] == '+':
        flag = False
        continue
    if flag:
        a = 10 * a + inMap[e]
    else:
        b = 10 * b + inMap[e]

c = a+b
l = 7*[""]
for j, e in enumerate(l):
    for i in reversed(range(len(str(c)))):

        l[j] += outMap[(c // (10 ** i)) % 10][5 * j:5 * j + 5]
        if i > 0:
            l[j] += '.'

for e in l:
    print(e)
