Lines = 4*[None]
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
