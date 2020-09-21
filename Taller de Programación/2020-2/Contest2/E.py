Lines = 4 * [None]
for i in range(4):
    Lines[i] = list(map(int, input().split()))
    if Lines[i][0] == Lines[i][2]:
        Lines[i][1], Lines[i][3] = min(
            Lines[i][1], Lines[i][3]), max(Lines[i][1], Lines[i][3])
    elif Lines[i][1] == Lines[i][3]:
        Lines[i][0], Lines[i][2] = min(
            Lines[i][0], Lines[i][2]), max(Lines[i][0], Lines[i][2])
    else:
        print("NO")
        exit(0)

Lines.sort()
for i in range(4):
    if Lines[i][:2] == Lines[i][2:]:
        print("NO")
        exit(0)
#print(Lines)
if Lines[0][:2] == Lines[1][:2] and Lines[0][2:] == Lines[2][:2] and Lines[1][2:] == Lines[3][:2] and Lines[2][2:] == Lines[3][2:]:
    for i in range(3):
        if Lines[i] == Lines[i + 1]:
            print("NO")
            exit(0)
    print("YES")
else:
    print("NO")
