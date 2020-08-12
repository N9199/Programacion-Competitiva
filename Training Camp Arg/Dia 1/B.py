n, m = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A.sort(reverse=True)
B.sort(reverse=True)
sumA = sum(A)
sumB = sum(B)
ansA = sumB
ansB = sumA

for i in range(1, n):
    ansA += min(A[i],sumB)
for i in range(1, m):
    ansB += min(B[i], sumA)
print(min(ansA,ansB))