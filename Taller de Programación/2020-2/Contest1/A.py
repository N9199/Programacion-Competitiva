from collections import deque
n, q = list(map(int, input().split()))
a = deque(map(int, input().split()))
t = 2*n
li = t*[None]
for i in range(t):
    c = a.popleft()
    b = a.popleft()
    li[i] = (str(c), str(b))
    if b < c:
        b, c = c, b
    a.appendleft(b)
    a.append(c)

start = 0
while li[start] != li[start + n - 1]:
    start += 1
for _ in range(q):
    m = int(input())
    m-=1
    if m > start:
        m -= start
        m %= (n - 1)
        m += start
    print(' '.join(li[m]))