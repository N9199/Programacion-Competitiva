n = int(input())
s =set()
for _ in range(n):
    st =input().strip().split('@')
    st[0]=st[0].replace('.','')
    st[0] = st[0].split('+')[0]
    st=st[0]+'@'+st[1]
    s.add(st)
print(len(s))