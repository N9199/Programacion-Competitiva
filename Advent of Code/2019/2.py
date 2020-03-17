import copy


def op(f):
    def func(l, i):
        l[l[i + 3]] = f(l[l[i + 1]], l[l[i + 2]])
        return True
    return func


def func(li):
    i = 0
    opcode = {
        1: op(lambda x, y: x+y),
        2: op(lambda x, y: x*y),
        99: (lambda x, y: False)
    }
    while i < len(li) and opcode.get(li[i], (lambda x, y: False))(li, i):
        i += 4
    return li[0]


li = list(map(int, input().split(',')))
for i in range(100):
    for j in range(100):
        l = copy.deepcopy(li)
        l[1] = i
        l[2] = j
        # print(i, j, l[:4])
        if func(l) == 19690720:
            print(100 * i + j)
            break
