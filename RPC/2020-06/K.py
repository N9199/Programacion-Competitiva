from sys import stderr
def dist(a, b):
    return max(abs(a[0]-b[0]),abs(a[1]-b[1]))

m = {}
for i in range(ord('a'), ord('j')):
    m[chr(i)] = (0,i-ord('a'))
for i in range(ord('j'), ord('s')):
    m[chr(i)] = (1,i-ord('j'))
for i in range(ord('s'), ord('z')+1):
    m[chr(i)] = (2,i-ord('s'))

n = int(input())
for _ in range(n):
    s1, s2 = input().split()
    if len(s1) != len(s2):
        print(3)
    elif s1 == s2:
        print(1)
    else:
        a = True
        for i in range(len(s1)):
            if dist(m[s1[i]], m[s2[i]]) > 1:
                a = False
                #print(s1[i],s2[i],m[s1[i]], m[s2[i]],file=stderr)
                break
        if a:
            print(2)
        else:
            print(3)
