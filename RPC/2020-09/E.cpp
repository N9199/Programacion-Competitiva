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
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)
#define pb push_back
#define eb emplace_back

#define debugx(x)  cerr << #x << ": " << x << endl

#define debugv(v)  //      \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

#define debugm(m)  //           \
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

vector<ll> dp;
vector<ll> val;
graph g;
ll t;
inline ll cost(int u, int v)
{
    ll temp1 = val[u]%t + 1, temp2 = val[v];
    if (temp1 > temp2)
        swap(temp1, temp2);
    return min(temp2 - temp1, t + temp1 - temp2);
}

ll func(int u)
{
    if (dp[u] != -1)
        return dp[u];
    dp[u] = 1e18;
    for (auto v : g[u])
        dp[u] = min(dp[u], func(v) + cost(u, v));
    return dp[u];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> t >> n;
    graph layer(n);
    int a;
    val.reserve(n * 10 + 1);
    val.eb(0);
    rep(i, n)
    {
        cin >> a;
        layer[i].assign(a,-1);
        rep(j, a)
        {
            cin >> layer[i][j];
            val.eb(layer[i][j]);
            layer[i][j] = val.size() - 1;
        }
    }
    g.resize(val.size());
    dp.assign(val.size(), -1);
    for (auto u : layer[0])
        g[0].eb(u);
    rep(i, n - 1) for (auto u : layer[i]) for (auto v : layer[i + 1]) g[u].eb(v);
    for (auto u : layer[n - 1])
        dp[u] = 0;
    cout << func(0) << '\n';
    debugv(dp);
    debugv(val);
    debugm(layer);
}