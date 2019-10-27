#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

vi visited;
void dfs1(graph &g, int u)
{
    visited[u] = 0;
    for (auto v : g[u])
        if (visited[v] == -1)
        {
            dfs1(g, v);
        }
}

void dfs2(graph &g, int u, int c)
{
    visited[u] = c;
    for (auto v : g[u])
        if (visited[v] == -1 or (visited[v] != 0 and visited[v] < c))
        {
            dfs2(g, v, c);
        }
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    graph g(n);
    visited.assign(n, -1);
    rep(_, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
    }
    dfs1(g, s);

    rep(i, n)
    {
        if(i == s)
            continue;
        if (visited[i] == -1)
        {
            dfs2(g, i, i);
        }
    }
    debugm(g);
    debugv(visited);
    set<int> diff;
    for (auto v : visited)
    {
        diff.emplace(v);
    }
    debugv(diff);

    cout << diff.size() - 1;
}