from math import ceil, floor

t = int(input())
for _ in range(t):
    a, b, c = list(map(int, input().split()))
    d1, d2 = floor(c / b), ceil(c / b)
    e1, e2 = floor(b/a), ceil(b/a)
    print(d1, d2, e1, e2)
    ans = int(3e4)
    # Case 1 (d1)
    # Case 1.1 floor on c/d1
    b1 = floor(c / d1)
    if b1 % a == 0:
        ans = min(ans, abs(b - b1))
    else:
        # Case 1.1.1 floor on b1/a
        pass
    # Case 1.2 ceil on c/d1
    b1 = ceil(c / d1)
    if b1 % a == 0:
        ans = min(ans, abs(b - b1))
    else:
        # Case 1.2.1 floor on b1/a
        pass
    # Case 2 (d2)
