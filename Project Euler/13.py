sum = 0
try:
    for i in range(101):
        n = int(input())
        sum += n
except:
    pass
print(str(sum)[:10])
