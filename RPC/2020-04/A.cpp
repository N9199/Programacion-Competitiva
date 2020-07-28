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
#define umap unordered_map

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
graph g;
vi t;
vector<umap<int, ll>> w;
vector<umap<int, ll>> dp1;
vector<umap<int, ll>> c;
vi dp2;
vi dp3;
ll func1(int u, int v)
{
    if (dp1[u].find(v) != dp1[u].end())
        return dp1[u][v];
    ll ans = t[v];
    c[u][v] = 1;
    for (auto x : g[v])
        if (x != u)
        {
            ans += func1(v, x);
            c[u][v] += c[v][x];
        }
    return dp1[u][v] = ans;
}

void dfs(int u, int v)
{
    if (dp2[v] >= 0)
        return;
    dp3[v] = dp3[u] - w[v][u] * (func1(u, v) - func1(v, u));
    dp2[v] = dp2[u] - w[v][u] * (c[u][v] - c[v][u]);
    for (auto x : g[v])
        if (x != u)
            dfs(v, x);
}

void dfs2(int u, int v, vi &d)
{
    d[v] = d[u] + w[u][v];
    for (auto x : g[v])
        if (x != u)
            dfs2(v, x, d);
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    t.resize(n);
    w.resize(n);
    c.resize(n);
    dp1.resize(n);
    dp2.assign(n, -1e9);
    dp3.assign(n, -1e9);
    ll t_accum = 0;
    rep(i, n)
    {
        cin >> t[i];
        t_accum += t[i];
    }
    int u, v, wi;
    rep(_, n - 1)
    {
        cin >> u >> v >> wi;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
        w[u][v] = w[v][u] = wi;
    }

    rep(i, n) if (g[i].size() == 1)
    {
        dp1[i][g[i][0]] = t_accum - t[i];
        c[i][g[i][0]] = n - 1;
    }
    vi dist(n, -1);
    rep(i, n) if (g[i].size() == 1 and dp2[i] < 0)
    {
        func1(i, g[i][0]);
        dist[i] = 0;
        dfs2(i, g[i][0], dist);
        dp2[i] = 0;
        dp3[i] = 0;
        rep(j, n) if (i != j)
        {
            dp2[i] += dist[j];
            dp3[i] += dist[j] * t[j];
        }
        dfs(i, g[i][0]);
    }

    rep(i, n) cout << t[i] * dp2[i] + dp3[i] << '\n';
}