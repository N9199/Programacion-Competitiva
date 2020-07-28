n = input()
temp = int(n[-3:])
if temp % 8 == 0 or temp % 8 == 5:
    print(n)
elif 0 < temp % 8 < 5:
    print(n[:-3] + str(temp + (5 - temp % 8)))
else:
    print(n[:-3] + str(temp + (8 - temp % 8)))
