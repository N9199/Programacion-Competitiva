#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m) //           \
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

int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n);
    int u, v;
    rep(_, m)
    {
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }

    queue<int> q;
    q.emplace(0);
    vi dist(n, -1);
    dist[0] = 0;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }
    cout << dist[n - 1] - 1 << '\n';
}