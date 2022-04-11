from random import randint

n = 25

for i in range(n):
    a = randint(10**(4*i),10**(4*i+4))
    b = randint(10**(4*i),10**(4*i+4))
    if a>b:
        a,b=b,a
    with open(f"p1/test{i}",'w') as f:
        f.write(f"{a} {b}")
