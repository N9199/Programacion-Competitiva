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

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m) //                                       \
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
    _os << _p.first << ' ' << _p.second;
    return _os;
}

class LcaTree
{
    int n;
    vi parent;
    vi level;
    vi root;
    graph P;
    graph Pmin;
    graph Pmax;

public:
    LcaTree(int n)
    {
        this->n = n;
        parent.assign(n, -1);
        level.assign(n, -1);
        P.assign(n, vi(lg(n) + 1, -1));
        Pmin.assign(n, vi(lg(n) + 1, 1e9));
        Pmax.assign(n, vi(lg(n) + 1, -1));
        root.assign(n, -1);
    }
    void addLeaf(int index, int Par, int w)
    {
        parent[index] = Par;
        level[index] = level[Par] + 1;
        P[index][0] = Par;
        Pmin[index][0] = w;
        Pmax[index][0] = w;
        debugx(w);
        root[index] = root[Par];
        for (int j = 1; (1 << j) < n; ++j)
        {
            if (P[index][j - 1] != -1)
            {
                P[index][j] = P[P[index][j - 1]][j - 1];
                if (P[index][j] != -1)
                {
                    Pmin[index][j] = min(Pmin[P[index][j - 1]][j - 1], Pmin[index][j - 1]);
                    Pmax[index][j] = max(Pmax[P[index][j - 1]][j - 1], Pmax[index][j - 1]);
                }
            }
        }
    }
    void addRoot(int index)
    {
        parent[index] = index;
        level[index] = 0;
        root[index] = index;
    }
    par lca(int u, int v)
    {
        debugx(u);
        debugx(v);
        debugm(Pmin);
        debugm(Pmax);
        debugm(P);
        if (root[u] != root[v] || root[u] == -1)
            return {1e9, -1};
        if (level[u] < level[v])
            swap(u, v);
        int dist = level[u] - level[v];
        int lmin = 1e9, lmax = -1;

        while (dist != 0)
        {
            int raise = lg(dist);
            lmin = min(lmin, Pmin[u][raise]);
            lmax = max(lmax, Pmax[u][raise]);
            u = P[u][raise];
            dist -= (1 << raise);
        }
        if (u == v)
            return {lmin, lmax};
        for (int j = lg(n); j >= 0; --j)
        {
            if (P[u][j] != -1 && P[u][j] != P[v][j])
            {
                lmin = min({lmin, Pmin[u][j], Pmin[v][j]});
                lmax = max({lmax, Pmax[u][j], Pmax[v][j]});
                u = P[u][j];
                v = P[v][j];
            }
        }
        return {min({lmin, Pmin[u][0], Pmin[v][0]}), max({lmax, Pmax[u][0], Pmax[v][0]})};
    }
};

int main()
{
    int n;
    cin >> n;
    int a, b, c;
    LcaTree l(n);
    wgraph g(n);
    rep(i, n - 1)
    {
        cin >> a >> b >> c;
        a--, b--;
        g[a].eb(c, b);
        g[b].eb(c, a);
    }

    vi visited(n, 1);
    queue<int> q;

    q.emplace(0);
    visited[0] = 0;
    l.addRoot(0);
    while (not q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : g[u])
        {
            if (visited[v.second])
            {
                l.addLeaf(v.second, u, v.first);
                q.emplace(v.second);
                visited[v.second] = 0;
            }
        }
    }
    int k;
    cin >> k;
    int d, e;
    rep(i, k)
    {
        cin >> d >> e;
        d--;
        e--;
        cout << l.lca(d, e) << '\n';
    }
}