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
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
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

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

vi visited;
graph g;
vi cycle;
vi ind;
bool flag = false;

void dfs(int u, int c, int l)
{
    if (visited[u] > c)
        return;
    visited[u] = c;
    for (int v : g[u])
    {
        if (visited[v] == 0)
            dfs(v, c + 1, l);
        else if (!flag and visited[v] - visited[u] >= l)
        {
            cycle.eb(v);
            cycle.eb(u);
            flag = true;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    visited.assign(n, 0);
    rep(_, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    int l = ceil(sqrt(n));
    rep(i, n) dfs(i, 0, l);
    if (flag)
    {
    }
    else
    {

    }
}