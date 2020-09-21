t = int(input())
for _ in range(t):
    s = input().strip()
    c = 0
    temp = [1, 0]
    for i in range(1, len(s)):
        if s[i] != s[i - 1]:
            c ^= 1
        temp[c] += 1
    if min(temp) % 2:
        print("DA")
    else:
        print("NET")
