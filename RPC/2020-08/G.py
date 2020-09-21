import os
MOD = int(1e9)+7
t = int(input())
out = ""
for i in range(1, t + 1):
    n = int(input())
    if n % 2 == 0:
        n //= 2
        out += 'Case #{}: {}\n'.format(i, (n * (n + 1) * (7 * n * n + 6 * n + 2) // 6) % MOD)
    else:
        n -= 1
        n //= 2
        out += 'Case #{}: {}\n'.format(i, ((n + 1) * (n + 1) * (7 * n * n + 11 * n + 6) // 6) % MOD)

out = out.encode(encoding='UTF-8')
os.write(1, out)
