n = int(input())
l = list(map(int, list(input().split())))

s = sum(l)
temp = 0
if n == 2:
    print(abs(l[-1] - l[0]))
    exit(0)

for i in range(n):
    if temp >= s - temp:
        print(
            min(abs(2*temp-s), abs(2*(temp-l[i-1])-s))
        )
        exit(0)
    temp += l[i]

print(abs(2*l[-1]-s))
