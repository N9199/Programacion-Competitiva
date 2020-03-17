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

graph g;
vi a;
graph dp;

int func(int n, int p, vi &visited)
{
    if (dp[n][p] != -1)
        return dp[n][p];
    if ((a[n] + 1) % 2 == p)
        return dp[n][p] = 0;
    int ans = 1e9;
    for (auto u : g[n])
    {
        if (visited[u]<2)
        {
            visited[u]++;
            ans = min(ans, func(u, p, visited) + 1);
        }
    }
    return dp[n][p] = ans;
}

int main()
{
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    g.assign(n + 1, vi());
    dp.assign(n + 1, vi(2, -1));
    rep(i, n)
    {
        cin >> a[i + 1];
        if (i + 1 - a[i + 1] >= 1)
            g[i + 1].eb(i + 1 - a[i + 1]);
        if (i + 1 + a[i + 1] <= n)
            g[i + 1].eb(i + 1 + a[i + 1]);
    }
    vi ans(n);
    vi visited(n + 1, 0);
    rep(i, n)
    {
        ans[i] = func(i + 1, a[i + 1] % 2, visited);
        ans[i] = (ans[i] == 1e9) ? -1 : ans[i];
    }
    print(ans);
}