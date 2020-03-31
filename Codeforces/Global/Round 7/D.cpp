#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
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

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v)         \
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
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

const int MAXLEN = 1e6;

class rollingHashing
{
    static const ull base = 127;
    static const vector<ull> primes;
    static vector<vector<ull>> POW;

    static ull add(ull x, ull y, int a) { return (x + y) % primes[a]; }
    static ull mul(ull x, ull y, int a) { return (x * y) % primes[a]; }

    static void init(int a)
    {
        if (POW.size() <= a + 1)
        {
            POW.eb(MAXLEN, 1);
        }
        repx(i, 1, MAXLEN) POW[a][i] = mul(POW[a][i], base, a);
    }

    static void init() { rep(i, primes.size()) init(i); }

    vector<vector<ull>> h;
    int len;
    rollingHashing(string &s)
    {
        len = s.size();
        h.assign(primes.size(), vector<ull>(len, 0));
        rep(a, primes.size())
        {
            h[a][0] = s[0] - 'a'; // Assuming alphabetic alphabet
            repx(i, 1, len) h[a][i] = add(s[i] - 'a', mul(h[a][i - 1], base, a), a);
        }
    }

    ull hash(int i, int j, int a) // Inclusive-Exclusive [i,i)?
    {
        if (i == 0)
            return h[a][j - 1];
        return add(h[a][j - 1], primes[a] - mul(h[a][i - 1], POW[a][j - i], a), a);
    }

    ull hash(int i, int j) // Supports at most two primes
    {
        return hash(i, j, 1) << 32 |
               hash(i, j, 0); // Using that 1e18<__LONG_LONG_MAX__
    }

    ull hash() { return hash(0, len); } // Also supports at most two primes
};

const vector<ull> rollingHashing ::primes({(ull)1e9 + 7,
                                           (ull)1e9 + 9}); // Add more if needed
