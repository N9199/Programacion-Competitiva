
def delta(dx, dy):
    def move(p, d):
        return (p[0] + d * dx, p[1] + d * dy)
    return move


def intersect(p1, q1, p2, q2):
    print(p1, p2, q1, q2)
    if p1[0] == p2[0] and q1[1] == q2[1]:
        if min(p1[1], p2[1]) <= q1[1] <= max(p1[1], p2[1]) and min(q1[0], q2[0]) <= p1[0] <= max(q1[0], q2[0]):
            return (p1[0], q1[1])
    elif p1[1] == p2[1] and q1[0] == q2[0]:
        if min(q1[1], q2[1]) <= p1[1] <= max(q1[1], q2[1]) and min(p1[0], p2[0]) <= q1[0] <= max(p1[0], p2[0]):
            return (q1[0], p1[1])


def dist(p1, p2):
    return abs(p1[0]-p2[0])+abs(p1[1]-p2[1])


li1 = list(map(lambda x: [x[0], int(x[1:])], input().split(',')))
li2 = list(map(lambda x: [x[0], int(x[1:])], input().split(',')))

print(len(li1), len(li2))
points = set()

di = {
    'D': delta(0, -1),
    'R': delta(1, 0),
    'L': delta(-1, 0),
    'U': delta(0, 1)
}
origin = (int(1e4), int(1e4))
p1 = origin
for ins1 in li1:
    p2 = origin
    for ins2 in li2:
        points.add(
            intersect(p1, p2,
                      di[ins1[0]](p1, ins1[1]),
                      di[ins2[0]](p2, ins2[1])
                      )
        )
        p2 = di[ins2[0]](p2, ins2[1])
    di[ins1[0]](p1, ins1[1])

points.remove(None)
ans = points.pop()
if ans == origin:
    ans = points.pop()
for p in points:
    # print(p)
    if p == origin:
        continue
    if dist(p, origin) < dist(ans, origin):
        ans = p

print(ans)
print(dist(ans, origin))
