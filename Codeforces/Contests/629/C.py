t = int(input())
for _ in range(t):
    n = int(input())
    x = input().strip()
    flag = False
    ans1 = ""
    ans2 = ""
    for c in x:
        if c=='0':
            ans1+='0'
            ans2+='0'
        elif flag:
            ans1+='0'
            ans2+=c
        elif c=='1':
            ans1+='1'
            ans2+='0'
            flag = True
        else:
            ans1+='1'
            ans2+='1'
    print(ans1)
    print(ans2)