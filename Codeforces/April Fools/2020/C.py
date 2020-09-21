n = int(input())
n = bin(n)[2:][::-1]
n += (6-len(n))*"0"
m = {0: 4, 1: 1, 2: 3, 3: 2, 4: 0, 5: 5}
ans = 6 * [None]
for i in range(6):
    ans[m[i]] = n[i]

print(int(''.join(ans[::-1]), 2))
