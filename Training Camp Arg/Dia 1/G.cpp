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

int bfs1(int start, graph &g)
{
    vi visited(g.size());
    queue<int> q;
    q.emplace(start);
    visited[start] = 1;
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto v : g[u])
            if (visited[v] == 0)
            {
                visited[v] = 1;
                q.emplace(v);
            }
    }
    return u;
}
int bfs2(int start, graph &g, vi &dist)
{
    queue<int> q;
    q.emplace(start);
    dist[start] = 0;
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto v : g[u])
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
    }
    return u;
}

void bfs3(int start, graph &g, vi &dist)
{
    vi dist2(g.size(), -1);
    queue<int> q;
    dist2[start] = 0;
    q.emplace(start);
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto v : g[u])
            if (dist2[v] == -1)
            {
                dist2[v] = dist2[u] + 1;
                dist[v] = max(dist[v], dist2[v]);
                q.emplace(v);
            }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    graph g(n);
    vi dist(n, -1);
    rep(_, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    bfs3(bfs2(bfs1(0, g), g, dist), g, dist);
    bool yes = true;
    bool temp = true;
    // Check if root is unique
    rep(i, n) if (dist[i] == k)
    {
        if (g[i].size() < 3)
            yes = false;
        if (temp)
            temp = false;
        else
        {
            yes = false;
            break;
        }
    }
    // Check if every leaf is part of a diameter
    rep(i, n) if (g[i].size() == 1)
    {
        if (dist[i] != 2 * k)
        {
            yes = false;
            break;
        }
    }

    rep(i, n) if (g[i].size() != 1 and dist[i] != k and g[i].size() <= 3) yes = false;
    if (yes)
        cout << "Yes\n";
    else
        cout << "No\n";
}