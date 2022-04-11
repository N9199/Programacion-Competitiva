out = 1001*[0]
i = 1
n=1
while i<=1000:
    out[i]=n
    n+=1
    while n%3==0 or n%10==3:
        n+=1

    i+=1

t = int(input())
for _ in range(t):
    print(out[int(input())])