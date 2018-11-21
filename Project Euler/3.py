from math import floor, sqrt


def sieve(n):
    limit = int(floor(sqrt(n)))+1
    isprime = max(n, 2)*[True]
    isprime[0] = isprime[1] = False

    i = 2
    while i < limit:
        assert(i < len(isprime))
        if isprime[i]:
            j = i
            while j*j < n:
                isprime[j] = False
                j += i

    primes = []
    for i in range(2, n-1):
        if isprime[i]:
            primes.append(i)

    return primes


n = 600851475143
primes = sieve(n)

for p in reversed(primes):
    if n % p == 0:
        print(p)
        break
