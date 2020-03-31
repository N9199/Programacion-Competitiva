from random import *

TOTAL_CASES = 10

FILE = "test.txt"

DMIN,DMAX = 50,100
PMIN,PMAX = 50,100
RMIN,RMAX = 1,1000
BMIN,BMAX = 1,1000
TMIN,TMAX = 1,100

with open(FILE,"w") as file:
    for case in range(TOTAL_CASES):
        D = randint(DMIN,DMAX)
        P = randint(PMIN,PMAX)
        R = randint(RMIN,min(RMAX,D*P))
        B = randint(BMIN,BMAX)
        base = {(a+1,b+1) for a in range(D) for b in range(P)}
        X = sample(base,R)
        file.write(str(D)+" "+str(P)+" "+str(R)+" "+str(B)+"\n")
        for i in range(D):
            file.write(str(randint(TMIN,TMAX))+"\n")
        for i in range(P):
            file.write(str(randint(TMIN,TMAX))+"\n")
        for x in X:
            file.write(str(x[0])+" "+str(x[1])+"\n")
