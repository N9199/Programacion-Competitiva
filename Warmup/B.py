t = int(input())
for _ in range(t):
    s1 = input()
    s2 = input()
    ans = ""
    for c1, c2 in zip(s1, s2):
        if c1 != c2:
            ans += "*"
        else:
            ans += "."
    print(s1)
    print(s2)
    print(ans)
    print()