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
vi col;
vii dp;
ii func(int u)
{
    if (g[u].size() == 0)
        return ii(0, u);
    if (dp[u].first != -1)
        return dp[u];
    ii ans = ii(0, -1);
    for (auto v : g[u])
    {
        ii temp = func(v);
        if (temp.first + (col[v] != col[u]) > ans.first)
        {
            ans.first = temp.first + (col[v] != col[u]);
            ans.second = temp.second;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    rep(_, t)
    {
        int n, m;
        cin >> n >> m;
        g.assign(n, vi());
        col.resize(n);
        dp.assign(n, ii(-1, -1));
        rep(i, n) cin >> col[i];
        int u, v;
        rep(_, m)
        {
            cin >> u >> v;
            u--, v--;
            g[v].eb(u);
        }
        ii ans = ii(0, -1);
        rep(i, n) ans = max(ans, func(i));
        rep(i, n) if (func(i).first == ans.first and col[func(i).second] != col[ans.second])
        {
            ans.first += 1;
            break;
        }
        cout << ans.first << '\n';
    }
}