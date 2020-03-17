#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

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

vi is_prime;
vi primes;

void criba()
{
    is_prime.resize(2e7);
    rep(i, 2e7) is_prime[i] = i;
    repx(i, 2, 2e7)
    {
        if (is_prime[i] == i)
        {
            primes.eb(i);
            if (i < sqrt(2e7))
                for (int j = i * i; j < 2e7; j += i)
                {
                    if (is_prime[j] == j)
                        is_prime[j] = i;
                }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    criba();
    if (n < 1001)
    {
        ll res = (n + 1) * (n + 1);
        while (k > 0)
        {
            if (is_prime[res] != res and is_prime[res] > n)
            {
                k--;
            }
            res++;
        }
        cout << res - 1 << '\n';
        return 0;
    }
    // vector<ll> poss;
    // poss.reserve(6e5);
    // int initial = 0;
    // while (primes[initial] <= n)
    //     ++initial;
    // for (int i = initial; i < initial + k; ++i)
    // {
    //     for (int j = i; j < initial + k; ++j)
    //     {
    //         poss.eb(primes[i] * primes[j]);
    //     }
    // }
    // sort(poss.begin(), poss.end());
    // cout << poss[k-1] << '\n';

    vector<ll> ops;
    int initial = 0;
    while (primes[initial] <= n)
        ++initial;
    int final = initial + 1;
    while (primes[final] * primes[final] < primes[initial]*primes[initial] * primes[initial])
        ++final;
    rep(i, k)
    {
        ops.emplace_back(primes[initial+i]);
    }
    for (int i = initial; i < final; ++i){
        for (int j = i; j < final; ++j){
            ops.eb(primes[i] * primes[j]);
        }
    }
    sort(ops.begin(), ops.end());
    vector<ll> res;
    res.reserve(6e5);
    for (int i = 0; i < k; ++i)
    {
        for (int j = i; j < k; ++j)
        {
            res.eb(ops[i] * ops[j]);
        }
    }
    sort(res.begin(), ops.end());
    cout << res[k - 1] << '\n';
}