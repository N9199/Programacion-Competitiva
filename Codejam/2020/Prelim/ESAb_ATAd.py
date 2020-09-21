def index(i, B, reverse):
    if reverse:
        return B-1-i
    return i


def value(v, xor):
    return v ^ xor


T, B = list(map(int, input().split()))
for _ in range(T):
    count = 0
    reverse = False
    xor = False
    a = B*[-1]
    known = 0
    checkable_index_r = -1
    checkable_index_x = -1
    while count < 150 and known < B:
        if count % 10 == 0:
            if checkable_index_x > -1:
                print(checkable_index_x+1)
                temp = int(input())
                xor = (temp != a[checkable_index_x])
                count += 1

            if checkable_index_r > -1:
                print(checkable_index_r+1)
                temp = int(input())
                reverse = (temp != a[checkable_index_r]) ^ xor
                count += 1

        print(index(index(known // 2, B, known % 2), B, reverse) + 1)
        count += 1
        a[index(known//2, B, known % 2)] = value(int(input()), xor)
        if checkable_index_r < 0 and known % 2 and a[B-1-known//2] != a[known//2]:
            checkable_index_r = known//2
        if checkable_index_x < 0 and known % 2 and a[B-1-known//2] == a[known//2]:
            checkable_index_x = known//2
        known += 1
    ans = B * [""]
    for i in range(B):
        ans[i] = str(value(a[index(i, B, reverse)], xor))
    print(''.join(ans))
    c = input().strip()
    if c == "N":
        break
