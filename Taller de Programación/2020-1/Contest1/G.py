Lines = 4*[None]
for i in range(4):
    Lines[i] = list(map(int, input().split()))
    if Lines[i][0] == Lines[i][2] and Lines[i][1] == Lines[i][3]:
        print("NO")
        exit(0)
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

if Lines[0] == Lines[1] or Lines[1] == Lines[2] or Lines[2] == Lines[3]:
    print("NO")
    exit(0)
if Lines[0][:2] == Lines[1][:2] and Lines[0][2:] == Lines[2][:2] and Lines[1][2:] == Lines[3][:2] and Lines[2][2:] == Lines[3][2:]:
    print("YES")
else:
    print("NO")
