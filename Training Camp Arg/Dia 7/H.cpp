#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

vi sieve(int n)
{
    vi primes;

    vector<bool> is_prime(n + 1, true);
    ll limit = (ll)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);

    return primes;
}

int main()
{
    ll n;
    cin >> n;
    vi primes = sieve(4e6);
    bool ans = false;
    for (auto p : primes)
    {
        if (p > n)
        {
            if (n != 1)
                ans = true;
            break;
        }

        if (n % p == 0)
        {
            int c = 0;
            while (n % p == 0)
            {
                c++;
                n /= p;
            }
            if ((sqrt(n) - floor(sqrt(n))) == 0)
            {
                ans = true;
                break;
            }
            else if (c % 2)
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}