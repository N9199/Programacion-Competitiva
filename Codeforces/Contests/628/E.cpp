#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

vi sieve(int n) {
  vi primes;

  vector<bool> is_prime(n + 1, true);
  int limit = (int)floor(sqrt(n));
  repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
      is_prime[j] = false;

  repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);

  return primes;
}

int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi primes = sieve(1e6);
    
}