n = int(input())
for _ in range(n):
    c, s = list(map(int, input().split()))
    if c >= s:
        print(s)
    else:
        print(((s//c)**2)*(c-(s % c))+(((s//c)+1)**2)*(s % c))
