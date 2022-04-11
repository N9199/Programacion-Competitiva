import random
import math
import time
from random import randint


def alg_ext_euclides(a: int, b: int) -> (int, int, int):
    r_0 = a
    s_0 = 1
    t_0 = 0
    r_1 = b
    s_1 = 0
    t_1 = 1
    while r_1 > 0:
        r_2 = r_0 % r_1
        s_2 = s_0 - (r_0 // r_1) * s_1
        t_2 = t_0 - (r_0 // r_1) * t_1
        r_0 = r_1
        s_0 = s_1
        t_0 = t_1
        r_1 = r_2
        s_1 = s_2
        t_1 = t_2
    return r_0, s_0, t_0


def es_potencia(n: int) -> bool:
    if n <= 3:
        return False

    k = 2
    lim = 4
    while lim <= n:
        if tiene_raiz_entera(n, k):
            return True
        k += 1
        lim *= 2
    return False


    
def tiene_raiz_entera(n: int, k: int) -> bool:
    if n <= 3:
        return False

    a = math.floor(math.log2(n)/k)
    i=a//2
    j=a
    while i <= j:
        if i==j:
            return n == pow(i,k)
        else:
            p = (i + j)//2 
            val = pow(p,k)
            if n == val:
                return True
            elif val < n:
                i = p+1
            else:
                j = p-1
    return False



def test_primalidad(n: int, k: int) -> bool:
    if es_potencia(n):
        return False

    neg = 0
    for i in range(k):
        a = random.randint(2,n-1)
        if math.gcd(a,n) > 1:
            return False
        b = pow(a,(n-1)//2,n)
        if b == n - 1:
            neg += 1
        elif b != 1:
            return False
    return neg>0


def sieve(n: int):
    is_prime = (n+1)*[True]
    limit = math.floor(math.sqrt(n))
    for i in range(2, limit+1):
        if is_prime[i]:
            for j in range(i*i,n+1,i):
                is_prime[j] = False
    return list(filter(lambda i: is_prime[i], range(3,n)))


        
if __name__ == "__main__":
    small_primes = sieve(int(5e2))
    a,b = list(map(int, input().split()))
    if a<=2 and 2<=b:
        print(2)
        exit(0)
    a += (a+1)%2
    out = -1
    #print((b-a)//2*len(small_primes))
    for n in range(a,b+1,2):
        flag = True
        for p in small_primes:
            if p > n:
                break
            if p == n:
                out = n
                break
            if p%n == 0:
                flag = False
                break
        if flag and test_primalidad(n,10):
            out = n
        if out != -1:
            break
    print(out)
