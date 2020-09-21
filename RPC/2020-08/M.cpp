#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, ll> par;
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
    os << p.first << ' ' << p.second;
    return os;
}

vector<ull> sieve(int n)
{
    vector<ull> primes;

    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);

    return primes;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    ull n, temp, ans;
    vector<ull> primes = sieve(1e6);
    unordered_set<ull> primes2;
    for (auto p : primes)
        primes2.emplace(p);
    int c = 0;
    rep(_, t)
    {
        cin >> n;
        temp = n;
        if (primes2.find(n) != primes2.end())
        {
            cout << "deficient\n";
            continue;
        }
        ans = 1;
        for (auto p : primes)
        {
            if (p > temp)
                break;
            if (ans > 2*n)
                goto f;
            c = 0;
            while (temp % p == 0)
            {
                temp /= p;
                c++;
            }
            ans *= (pow(p, c + 1) - 1) / (p - 1);
        }
        if (temp > 1)
            ans *= (temp + 1);
    f:
        ans -= n;
        if (ans > n)
            cout << "abundant\n";
        else if (ans < n)
            cout << "deficient\n";
        else
            cout << "perfect\n";
    }
}