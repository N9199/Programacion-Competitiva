#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;

typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gcd __gcd

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << ' ' << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct edge
{
    int u, v;
    ll w;
    edge(int u, int v, ll w) : u(u), v(v), w(w) {}

    bool operator<(const edge &o) const
    {
        return w < o.w;
    }
};

class MST
{
    int n;
    ll sum;
    vi parent;
    vi visited;
    vi rank;
    vi level;
    graph P;
    graph W;
    wgraph G;
    unordered_map<int, int> q;
    unordered_set<int> a;

    int findSet(int i)
    {
        return (parent[i] == i) ? i : parent[i] = findSet(parent[i]);
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void addEdge(edge e)
    {
        if (not isSameSet(e.u, e.v))
        {
            a.emplace(e.u * n + e.v);
            a.emplace(e.v * n + e.u);
            int u = findSet(e.u), v = findSet(e.v);
            if (rank[u] > rank[v])
            {
                parent[u] = v;
            }
            else
            {
                parent[v] = u;
            }
            G[u].eb(e.w, v);
            G[v].eb(e.w, u);
            if (rank[u] == rank[v])
                rank[v]++;

            sum += e.w;
        }
    }

    void dfs(int v)
    {
        visited[v] = 0;
        for (auto u : G[v])
        {
            if (visited[u.second])
            {
                addLeaf(u.second, v, u.first);
                dfs(u.second);
            }
        }
    }

    void addLeaf(int index, int par, ll w)
    {
        parent[index] = par;
        level[index] = level[par] + 1;
        P[index][0] = par;
        W[index][0] = w;
        for (int j = 1; (1 << j) < n; ++j)
        {
            if (P[index][j - 1] != -1)
            {
                P[index][j] = P[P[index][j - 1]][j - 1];
                W[index][j] = max(W[P[index][j - 1]][j - 1], W[index][j - 1]);
            }
        }
    }

  public:
    MST() {}

    void reset(int n, vector<edge> E)
    {
        this->n = n;
        sum = 0;
        parent.resize(n);
        rep(i, n) parent[i] = i;
        level.assign(n, -1);
        P.assign(n, vi(lg(n) + 1, -1));
        W.assign(n, vi(lg(n) + 1, -1));
        G.assign(n, vp());
        visited.assign(n, 1);
        rank.assign(n, 0);
        q.clear();
        a.clear();

        sort(E.begin(), E.end());

        for (auto e : E)
        {
            debugx(e.v);
            debugx(e.u);
            q[e.v * n + e.u] = e.w;
            q[e.u * n + e.v] = e.w;
            addEdge(e);
        }
        level[0] = 0;
        dfs(0);
    }

    int lca(int u, int v)
    {
        if (a.count(n * u + v) > 0)
            return sum;

        if (level[u] < level[v])
            swap(u, v);

        int dist = level[u] - level[v];
        ll m = 0;
        ll temp = q[u * n + v];
        while (dist != 0)
        {
            int raise = lg(dist);
            m = max(W[u][raise], m);
            u = P[u][raise];
            dist -= (1 << raise);
        }
        if (u == v)
            return sum - m + temp;

        for (int j = lg(n); j >= 0; --j)
        {
            if (P[u][j] != -1 && P[u][j] != P[v][j])
            {
                m = max(W[u][j], m);
                m = max(W[v][j], m);
                u = P[u][j];
                v = P[v][j];
            }
        }
        m = max(W[u][0], m);
        m = max(W[v][0], m);
        return sum - m + temp;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    MST g;
    while (cin >> n >> r)
    {
        vector<edge> e;
        rep(i, r)
        {
            int a, b, c;
            cin >> a >> b >> c;
            e.eb(--a, --b, c);
        }
        g.reset(n, e);

        int q;
        cin >> q;
        rep(i, q)
        {
            int u, v;
            cin >> u >> v;
            cout << g.lca(--u, --v) << '\n';
        }
    }
    return 0;
}