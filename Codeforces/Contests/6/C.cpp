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

// Or LLONG_MAX for ll
#define INF INT_MAX

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
#define debugm(m)                                  \
    cerr << #m << ":" << endl;                     \
    for (auto it = m.begin(); it != m.end(); it++) \
    {                                              \
        cerr << distance(m.begin(), it) << ":";    \
        for (auto e : *it)                         \
            cerr << " " << e;                      \
        cerr << endl;                              \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, " ")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

vi sieve(int n)
{
    vi primes;

    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);

    return primes;
}

int main()
{
    int r, c;
    cin >> r >> c;
    if (r + c == 2)
    {
        cout << 0 << '\n';
        return 0;
    }
    if (r + c == 3)
    {
        if (r < c)
            cout << 1 << ' ' << 2 << '\n';
        else
            cout << 1 << '\n'
                 << 2 << '\n';
        return 0;
    }
    auto primes = sieve(1e4);
    set<int> pprimes;
    for (auto p : primes)
    {
        auto temp = 1;
        while ((temp *= p) < 1e4)
            pprimes.insert(p);
    }
    bool flag = false;
    if (c < r)
    {
        flag = true;
        swap(c, r);
    }
    graph matrix(r, vi(c));
    auto it = pprimes.begin();
    int a = 0;
    int rt = 0, rc = 1;
    repx(i, 2, r + c + 2)
    {
        if (a == 0)
            matrix[rt++][0] = i;
        else
            matrix[0][rc++] = i;
        a++;
        a %= c;
    }
    repx(i, 1, r) repx(j, 1, c) { matrix[i][j] = matrix[i - 1][j] * matrix[i][j - 1]; }
    if (flag)
        swap(r, c);
    rep(i, r)
    {
        rep(j, c)
        {
            if (flag)
                swap(i, j);
            cout << matrix[i][j];
            if (flag)
                swap(i, j);
            if (j < c - 1)
                cout << " ";
            else
                cout << '\n';
        }
    }
}