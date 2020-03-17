#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

// Reps are inclusive exclusive (i.e. range is [a,b))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

// Base two log for ints and for ll
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

// Or LLONG_MAX for ll
#define INF INT_MAX

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) //cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v) //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m)             \
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, " ")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

ll mulmod(ull a, ull b, ull c)
{
    ull x = 0, y = a % c;
    while (b)
    {
        if (b & 1)
            x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll gcdext(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdext(b % a, a, &x1, &y1);

    // Update x and y using results of
    // recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll modularInverse(ll n, ll mod)
{
    ll x, y;
    ll g = gcdext(n, mod, &x, &y);
    return (x + mod) % mod;
}

const ll mod = 998244353;

int main()
{
    int n;
    cin >> n;
    vi a(n + 1, 1);
    vi accum_a(n + 1, 1);
    vi p100(n + 1, 1);
    repx(i, 1, n + 1)
    {
        cin >> a[i];
        accum_a[i] = mulmod(a[i], accum_a[i - 1], mod);
        p100[i] = mulmod(100, p100[i - 1], mod);
    }
    ll p = mulmod(accum_a[n], n, mod), q = p100[n];
    debugv(a);
    debugv(accum_a);
    debugv(p100);
    debugx(make_pair(p, q));
    repx(i, 1, n + 1)
    {
        q = ((q - mulmod(p100[n - i], mulmod(accum_a[i - 1], (100 - a[i]), mod), mod)) % mod + mod) % mod;                 //q-=100^(n-i)*a_1*...a_{i-1}(100-a_i)
        p = ((p + mulmod(i, mulmod(p100[n - i], mulmod(accum_a[i - 1], (100 - a[i]), mod), mod), mod)) % mod + mod) % mod; //p+=100^(n-i)*a_1*...a_{i-1}(100-a_i)*i
        debugx(make_pair(p, q));
    }
    cout << mulmod(p, modularInverse(q, mod), mod) << '\n';
}