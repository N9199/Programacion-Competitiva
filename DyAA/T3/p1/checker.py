import random

def test_miller_rabin(n: int, k: int) -> bool :
    """
    Argumentos :
        n: int - n >= 1
        k: int - k >= 1
    Retorna :
        bool - True si n es un numero primo, y False en caso contrario.
        La probabilidad de error del test es menor o igual a 2**(-k),
        e implementa el test de primalidad de Miller-Rabin.
    """
    if n == 1:
        return False
    elif n==2:
        return True
    elif n%2 == 0:
        return False
    else:
        s = 0
        d = n-1
        while d%2==0:
            s = s + 1
            d = d//2
        num = k//2 + 1
        for i in range(0,num):
            a = random.randint(2,n-1)
            pot = pow(a,d,n)
            if pot != 1 and pot != n-1:
                pasar = False
                for j in range(0,s):
                    pot = (pot*pot) % n
                    if pot == n-1:
                        pasar = True
                        break
                if pasar == False:
                    return False
        return True


if __name__ == "__main__":
    input_f, expected_f, output_f = list(input().strip().split())
    with open(input_f) as f:
        a,b = list(map(int, f.readline().split()))
    with open(expected_f) as f:
        p = int(f.readline())
    with open(output_f) as f:
        out = int(f.readline())
    if p == -1:
        if out!=-1:
            print("WA")#Change for whatever is needed
        else:
            print("ACC")
    else:
        if a<= out and out<= b and test_miller_rabin(out, 20):
            print("ACC")
        else:
            print("WA")

