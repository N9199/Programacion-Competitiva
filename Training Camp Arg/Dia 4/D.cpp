#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- >= (int)a;)

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
#define debugmp(m)               \
    cerr << #m << ":\n";         \
    for (auto v : m)             \
    {                            \
        cerr << v.first << ": "; \
        for (auto e : v.second)  \
            cerr << e << " ";    \
        cerr << "\n";            \
    }                            \
    cerr << endl

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

int main()
{
    int n, p;
    cin >> n >> p;
    map<ii, ll> g;
    vi d(n);
    int u, v;
    rep(i, n)
    {
        cin >> u >> v;
        u--, v--;
        g[ii(min(u, v), max(u, v))]++;
        d[u]++;
        d[v]++;
    }
    ll ans = 0;
    for (auto e : g)
        if (d[e.first.first] + d[e.first.second] - g[e.first] < p and d[e.first.first] + d[e.first.second] >= p)
            ans--;
    sort(d.begin(), d.end());
    rep(i, n - 1) ans += (ll)(d.end() - lower_bound(d.begin() + i + 1, d.end(), p - d[i]));
    cout << ans << '\n';
}