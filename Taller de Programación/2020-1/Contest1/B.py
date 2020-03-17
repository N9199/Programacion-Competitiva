from sys import stdin
for line in stdin.readlines():
    print(sum(list(map(int, line.split()))) / 2)