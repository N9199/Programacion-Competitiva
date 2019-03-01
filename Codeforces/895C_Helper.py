import math

n = 70
mod = int(1e9)+7


def checkPrimes():
    primes = [2, 3, 5, 7]
    out = "0,0"
    for i in range(2, n+1):
        if i in primes:
            out += ",1"
            continue
        for p in primes:
            if i % p == 0:
                out += ",0"
                break
        else:
            out += ",1"
    return out


def num(x):
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23,
              29, 31, 37, 41, 43, 47, 53, 59, 61, 67]
    if x in primes:
        return x
    m = mask(x)
    temp = 1
    for i, p in enumerate(primes):
        if m & (1 << i) != 0:
            temp *= p
    return temp


def mask(x):
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23,
              29, 31, 37, 41, 43, 47, 53, 59, 61, 67]
    if x in primes and x > 35:
        return 0
    m = 0
    b = 1
    for p in primes:
        while x > 1 and x % p == 0:
            x /= p
            m ^= b
        if x == 1:
            break
        b *= 2
    return m


def createMasks():
    out = "0"
    for i in range(1, n+1):
        out += ","+str(mask(num(i)))

    return out


def squareFree():

    out = "0"
    for i in range(1, n+1):
        out += ","+str(num(i))
    return out


isPrime = "vi isPrime = {"
masks = "vi masks = {"
rep = "vi repr = {"

close = "};"


print(isPrime+checkPrimes()+close)
print(masks+createMasks()+close)
print(rep+squareFree()+close)
