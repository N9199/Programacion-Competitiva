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
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, " ")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

vector<graph> dp;

vi X;
vi Y;

int S, B;

ll func(int n, int b, int delta)
{
    //debugx(make_pair(n,b));
    if (b == -1)
        return 0;
    if (n == -1)
        return 1e9;
    if (dp[n][b][delta] != -1)
        return dp[n][b][delta];
    ll ans = func(n - 1, b, delta);
    if (n > 0)
        ans = min(ans, func(n - 2, b - 1, delta) + (X[(n + delta) % S] + X[(n - 1 + delta) % S]) * Y[b]);
    return dp[n][b][delta] = ans;
}

int main()
{
    while (cin >> S >> B)
    {
        if (S == 0)
            return 0;
        dp.assign(S, graph(B, vi(S, -1)));
        X.assign(S, 0);
        Y.assign(B, 0);
        rep(i, S) cin >> X[i];
        rep(i, B) cin >> Y[i];
        ll ans = 1e18;
        rep(d, S)
        {
            //debugx(d);
            ans = min(ans, func(S - 1, B - 1, d));
        }
        cout << -ans << '\n';
    }
}