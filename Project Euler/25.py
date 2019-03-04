a = 1
b = 1
i = 2
while len(str(a)) < 1000 and len(str(b)) < 1000:
    a = a + b
    b = a + b
    i += 2

print(
    "{}: {}\n{}: {}".format(
        i-1, a,
        i, b
    )
)
