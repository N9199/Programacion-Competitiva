m = [[] for _ in range(26)]
s = input().strip()
n = int(input())
for _ in range(n):
    temp = input().strip()
    m[ord(temp[0]) - ord('a')].append(temp)

if m[ord(s[-1]) - ord('a')]:
    for e in m[ord(s[-1]) - ord('a')]:
        if not m[ord(e[-1]) - ord('a')]:
            print(e + "!")
            exit(0)
        elif len(m[ord(e[-1]) - ord('a')]) == 1 and e[0]==e[-1]:
            print(e+"!")
            exit(0)

    print(m[ord(s[-1]) - ord('a')][0])
else:
    print("?")
    

