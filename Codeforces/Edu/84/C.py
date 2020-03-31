n,m,k = list(map(int, input().split()))
s = k*[None]
e = k*[None]
min_x = n
min_y = m

for i in range(k):
    s[i] = list(map(int, input().split()))
    min_x = min(min_x, s[i][0])
    min_y = min(min_y, s[i][1])
for i in range(k):
    e[i] = list(map(int, input().split()))

if n<=2 and m<=2:
    pass #exit(0)
ans = (n-min_x)*"D"+(m-min_y)*"R"

pos = [n,m]
e.sort(key=lambda x: pos[0]-x[0]+pos[0]-x[1])
while len(e)>0:
    p = e.pop(0)
    delta_x = pos[0]-p[0]
    if delta_x > 0:
        ans+=delta_x*"U"
    else:
        ans+= (-delta_x)*"D"
    delta_y = pos[1]-p[1]
    if delta_y > 0:
        ans+=delta_y*"L"
    else:
        ans+= (-delta_y)*"R"
    pos = p
    e.sort(key=lambda x: pos[0]-x[0]+pos[0]-x[1])

print(len(ans))
print(ans)



