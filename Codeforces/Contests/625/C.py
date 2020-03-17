n = int(input())
s = list(map(lambda x: ord(x) - ord(a), input().strip()))
ans = 0
first = n * [-1]
end = n * [-1]
first[0] = 0
end[n-1] = n-1
last = s[0]
next = s[n-1]
for i in range(1, n):
    if s[i] == last:
        first[i] = first[i - 1]
    else:
        last = s[i]
        first[i] = i
    if s[n - 1 - i] == next:
        end[n - 1 - i] = end[n - i]
    else:
        next = s[n - 1 - i]
        end[n-1-i] = n-1-i

l = []
i = n - 1
while i >= 0:
    l.append(s[i], first[i], i)
    i = first[i] - 1
l.sort()

while len(l):
    