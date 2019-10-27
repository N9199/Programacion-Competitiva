input()
l = list(map(int, list(input().split())))
l.sort()
temp = []
i = 0
while i+1 < len(l):
    if l[i] == l[i + 1]:
        temp.append(l[i])
        i += 1
    i += 1

print(len(temp)//2)
