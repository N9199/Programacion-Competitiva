t = int(input())
li = list(map(int, input().split()))

for n in li:
    if n < 15:
        print("NO")
    elif 0 < n % 14 < 7:
        print("YES")
    else:
        print("NO")
