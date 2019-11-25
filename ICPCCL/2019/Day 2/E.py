w, m, k = list(map(int, list(input().split())))
w = w // k
logm = len(str(m))
nextpow = 10 ** (logm) - m
total = 0
while (w >= logm * nextpow):
    total += nextpow
    w -= logm * nextpow
    nextpow = 9*(10**logm)
    logm += 1
total += w // logm
print(total)
