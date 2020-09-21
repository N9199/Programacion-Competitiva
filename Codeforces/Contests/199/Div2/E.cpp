#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

// Reps are inclusive exclusive (i.e. range is [a,b))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

// Base two log for ints and for ll
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) //cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v) //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m) //            \
    cerr << #m << ":" << endl; \
    for (auto v : m)           \
    {                          \
        for (auto e : v)       \
            cerr << " " << e;  \
        cerr << endl;          \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

class LcaForest
{
    int n;
    vi parent;
    vi level;
    vi root;
    graph P;

public:
    LcaForest() {}
    void build(graph &g)
    {
        n = g.size();
        parent.assign(n, -1);
        level.assign(n, -1);
        P.assign(n, vi(lg(n) + 1, -1));
        root.assign(n, -1);
        vi visited(n);
        function<void(int, int)> dfs = [&](int u, int par) {
            visited[u] = 1;
            if (par != -1)
                addLeaf(u, par);
            for (auto v : g[u])
                if (v != par and !visited[v])
                    dfs(v, u);
        };
        rep(i, n) if (!visited[i])
        {
            addRoot(i);
            dfs(i, -1);
        }
    }
    void addLeaf(int index, int par)
    {
        parent[index] = par;
        level[index] = level[par] + 1;
        P[index][0] = par;
        root[index] = root[par];
        for (int j = 1; (1 << j) < n; ++j)
        {
            if (P[index][j - 1] != -1)
                P[index][j] = P[P[index][j - 1]][j - 1];
        }
    }
    void addRoot(int index)
    {
        parent[index] = index;
        level[index] = 0;
        root[index] = index;
    }
    int distance(int u, int v)
    {
        if (root[u] != root[v] || root[u] == -1)
            return -1;
        if (level[u] < level[v])
            swap(u, v);
        int du = u, dv = v;
        int dist = level[u] - level[v];
        while (dist != 0)
        {
            int raise = lg(dist);
            u = P[u][raise];
            dist -= (1 << raise);
        }
        if (u == v)
            return level[du] + level[dv] - 2 * level[u];
        for (int j = lg(n); j >= 0; --j)
        {
            if (P[u][j] != -1 && P[u][j] != P[v][j])
            {
                u = P[u][j];
                v = P[v][j];
            }
        }
        return level[du] + level[dv] - 2 * level[parent[u]];
    }
};

class Centroid
{
    LcaForest Tree;
    vi d;
    vi p;
    vi col;
    vi min_dist;
    int n;

    void find_centroids(int root, int par, graph &g)
    {
        static vi sz(g.size());
        function<void(int, int)> get_sz = [&](int u, int prev) {
            sz[u] = 1;
            for (auto v : g[u])
                if (v != prev and p[v] == -2)
                {
                    get_sz(v, u);
                    sz[u] += sz[v];
                }
        };
        get_sz(root, -1);
        int n = sz[root];
        int centroid = -1;
        function<void(int, int)> dfs = [&](int u, int prev) {
            bool is_centroid = true;
            for (auto v : g[u])
                if (v != prev and p[v] == -2)
                {
                    dfs(v, u);
                    if (sz[v] > n / 2)
                        is_centroid = false;
                }
            if (n - sz[u] > n / 2)
                is_centroid = false;
            if (is_centroid)
                centroid = u;
        };
        dfs(root, -1);
        p[centroid] = par;
        for (auto v : g[centroid])
            if (p[v] == -2)
                find_centroids(v, centroid, g);
    }

public:
    Centroid(graph &g)
    {
        n = g.size();
        p.assign(n, -2);
        d.assign(n, -1);
        col.assign(n, 0);
        min_dist.assign(n, 1e9);
        find_centroids(0, -1, g);
        Tree.build(g);
    }
    int parent(int u) { return p[u]; }
    int depth(int u) { return (d[u] != -1) ? d[u] : ((parent(u) == -1) ? d[u] = 0 : d[u] = depth(parent(u)) + 1); }
    int dist(int u, int v) { return Tree.distance(u, v); }
    void update(int u)
    {
        col[u] = 1;
        min_dist[u] = 0;
        int v = u;
        while (v != -1)
        {
            if (dist(u, v) < min_dist[v])
                min_dist[v] = dist(u, v);
            v = p[v];
        }
    }
    int query(int u)
    {
        int v = u;
        int ans = min_dist[u];
        while (v != -1)
        {
            debugx(ans);
            debugx(ii(v, min_dist[v]));
            ans = min(ans, dist(u, v) + min_dist[v]);
            v = p[v];
        }
        return ans;
    }
    void debug()
    {
        debugv(p);
        debugv(min_dist);
        debugv(col);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n);
    rep(_, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    debugm(g);
    Centroid T(g);
    T.update(0);
    debugx("Built");
    rep(_, m)
    {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1)
            T.update(v);
        else
            cout << T.query(v) << '\n';
    }
}