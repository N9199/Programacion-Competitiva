n, a, r, m = list(map(int, input().split()))
h = list(map(int, input().split()))
left, right = min(h), max(h)
while left < right:
    mid = (right + left) // 2
    mid1 = mid
    mid2 = mid+1
    temp1 = 0
    temp2 = 0
    if m > a + r:
        for i in range(n):
            temp1 += max(0, h[i] - mid1) * r + max(0, mid1 - h[i]) * a
            temp2 += max(0, h[i] - mid2) * r + max(0, mid2 - h[i]) * a
    else:
        above1 = 0
        below1 = 0
        above2 = 0
        below2 = 0
        for i in range(n):
            above1 += max(0, h[i]-mid1)
            above2 += max(0, h[i]-mid2)
            below1 += max(0, mid1-h[i])
            below2 += max(0, mid2-h[i])
        temp1 = min(above1, below1) * m + max(0, above1 -
                                              below1) * r + max(0, below1 - above1) * a
        temp2 = min(above2, below2) * m + max(0, above2 -
                                              below2) * r + max(0, below2 - above2) * a
    if (temp2 - temp1 >= 0):
        right = mid
    else:
        left = mid+1


mid1 = left
temp1 = 0
if m > a + r:
    for i in range(n):
        temp1 += max(0, h[i] - mid1) * r + max(0, mid1 - h[i]) * a
else:
    above1 = 0
    below1 = 0
    for i in range(n):
        above1 += (h[i] > mid1)
        below1 += (h[i] < mid1)
    temp1 = min(above1, below1) * m + max(0, above1 -
                                          below1) * r + max(0, below1 - above1) * r
print(temp1)
