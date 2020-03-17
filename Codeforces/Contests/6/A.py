t = int(input())
for _ in range(t):
    s = input().strip()

    temp = 0
    for c in s:
        temp += int(c)

    if temp % 3 == 0 and '0' in s and (len(set(['2', '4', '6', '8']).intersection(set(s))) > 0 or len(set(s)) == 1 or (list(s).count('0') > 1 and '3' in s)):
        print("red")
    else:
        print("cyan")
