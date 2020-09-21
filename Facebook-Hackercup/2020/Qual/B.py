t = int(input())
for i in range(1, t + 1):
    m = {'A': 0, 'B': 1}
    n = int(input())
    b = sum(map(lambda x: m[x], input().strip()))
    ans = abs(2*b-n)
    print("Case #{}: {}".format(i, "Y"*(ans==1)+"N"*(ans>1)))