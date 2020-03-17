n, m = list(map(int, input().split()))
trees = list(map(int, input().split()))
trees.sort()
ans = m*[None]
free = []
temp_m = m
k = 0
for i in range(n - 1):
    diff = trees[i + 1] - trees[i] - 1
    for j in range(min((m // n), diff) // 2):
        ans[k] = trees[i] + 1 + j
        k += 1
        ans[k] = trees[i + 1] - 1 - j
        k += 1

    if min(diff, (m // n)) % 2 == 1:
        ans[k] = (trees[i] + trees[i + 1]) // 2
        k += 1

    if diff > m // n:
        free += [(trees[i] + 1 + j, 0), (trees[i + 1] - 1 - j, 1)]

    temp_m -= min(m//n, diff)

for j in range((m//n)//2):
    ans[k] = trees[-1] + 1 + j
    k += 1
    ans[k] = trees[0] - 1 - j
    k += 1

free += [(trees[0]-(m//n)//2-1, 1)]

if (m // n) % 2 == 1:
    ans[k] = trees[-1] + 1 + (m // n)//2
    k += 1
    free += [(trees[-1]+2+(m//n)//2, 0)]
else:
    free += [(trees[-1]+1+(m//n)//2, 0)]
free.sort()
temp_m -= (m // n)


while temp_m > 0:
    if temp_m == 1:
        ans[k] = free[0][0]
    else:
        if len(free) > 2:
            temp_m2 = temp_m
            n = len(free)//2
            for i in range(1, len(free), 2):
                diff = free[i + 1][0] - free[i][0] - 1
            for j in range(min((temp_m2 // n), diff) // 2):
                ans[k] = free[i][0] + 1 + j
                k += 1
                ans[k] = free[i + 1][0] - 1 - j
                k += 1

            if min(diff, (temp_m2 // n)) % 2 == 1:
                ans[k] = (free[i][0] + free[i + 1][0]) // 2
                k += 1

            if diff > temp_m2 // n:
                free += [(free[i][0] + 1 + j, 0),
                         (free[i + 1][0] - 1 - j, 1)]

            temp_m -= min(temp_m2 // n, diff)
            for j in range((temp_m2//n)//2):
                ans[k] = free[-1][0] + 1 + j
                k += 1
                ans[k] = free[0][0] - 1 - j
                k += 1

            free += [(trees[0]-(temp_m2//n)//2-1, 1)]

            if (m // n) % 2 == 1:
                ans[k] = trees[-1] + 1 + (m // n)//2
                k += 1
                free += [(trees[-1]+2+(m//n)//2, 0)]
            else:
                free += [(trees[-1]+1+(m//n)//2, 0)]
            free.sort()
            temp_m -= (temp_m2 // n)
        else:
            for j in range(temp_m//2):
                ans[k] = free[0][0] - j-1
                k += 1
                ans[k] = free[1][0] + j+1
                k += 1
            if temp_m % 2 == 1:
                ans[k] = ans[k-2]-1

ans.sort()
i = 0
j = 0
dist = 0
while j < m:
    while i < n-1 and abs(trees[i+1]-ans[j]) < abs(trees[i]-ans[j]):
        i += 1
    dist += abs(trees[i] - ans[j])
    j += 1

print(dist)
print(*ans)
