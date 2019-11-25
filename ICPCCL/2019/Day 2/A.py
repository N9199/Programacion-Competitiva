n, m = list(map(int, list(input().split())))

print((n % m)*((((n//m)+1)*(n//m))//2) +
      (m - (n % m))*((n//m)*(n//m-1)//2), ((n - m+1) * (n - m)) // 2)
