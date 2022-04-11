n = int(input())
li = list(map(int, input().split()))
s = set()
for i, e in enumerate(li):
    if i==n-1 and len(s)==1:
        s.add(-1)
        continue
    temp = e
    while temp in s:
        s.remove(temp)
        temp+=1
    s.add(temp)
if len(s)==2:
    print("Y")
else:
    print("N")