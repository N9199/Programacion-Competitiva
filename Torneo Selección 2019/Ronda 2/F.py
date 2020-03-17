

def main(d, s):
    for k in range(1, s):
        backtrack(d, s, k, 0, False)


def backtrack(d, s, k, n, f):
    if k <= 0 or s <= 0:
        if k == 0 and s == 0 and d % n == 0:
            print(n)
            exit(0)
    else:
        for i in range(0 if f else 1, min(10, s)):
            backtrack(d, s - i, k - 1, n * 10 + i, True)


d, s = list(map(int, input().split()))
main(d, s)
