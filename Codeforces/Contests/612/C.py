n = int(input())
bulbs = list(map(int, input().split()))
li = []
odds = 0
blanks = 0
for i, e in enumerate(bulbs):
    if e != 0:
        if e % 2 == 1:
            li.append((i, 1))
            odds += 1
        else:
            li.append((i, 0))
    else:
        blanks += 1

odds = (n+1)//2-odds
even = blanks-odds
ans = 0
spaces = []
if len(li) > 0 and li[0][0] != 0:
    li = [(-1, li[0][1])] + li

if len(li) > 0 and li[-1][0] != n-1:
    li = li+[(n, li[-1][1])]

for i in range(len(li)-1):
    if li[i][1] == li[i + 1][1]:
        temp = (
            li[i][0] == -1 or li[i + 1][0] == n,
            li[i + 1][0] - li[i][0] - 1,
            li[i][1]
        )
    else:
        temp = None
        ans += 1

    if temp is not None and temp[1] > 0:
        spaces.append(temp)

spaces.sort()
# print(odds, even, blanks, n)
for space in spaces:
    if space[2] == 0:
        if even < space[1]:
            ans += 1 if space[0] else 2
        else:
            even -= space[1]
    else:
        if odds < space[1]:
            ans += 1 if space[0] else 2
        else:
            odds -= space[1]

# print(spaces)
if len(li) == 0:
    ans = min(1, n-1)
print(ans)
