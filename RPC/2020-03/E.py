def remove(l: list, start: str, end: str):
    l[0].replace(start, '')
    if start != end:
        remove(l, chr(ord(start)+1), end)


def process(l: list, i, j):
    if 'shuffle' == l[0][i: i + 6]:
        pass
    elif 'sorted' == l[0][i: i + 6]:
        pass
    elif 'concat' == l[0][i: i + 6]:
        pass


A = input().strip()
B = input().strip()
