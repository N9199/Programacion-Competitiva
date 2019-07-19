a, b, c = list(map(int, input().rstrip().split()))
print("YES" if ((c != 0) and (((b % c)+c) % c == ((a % c)+c) % c and c*a <= c*b))
      or (a == b and c == 0) else "NO")
