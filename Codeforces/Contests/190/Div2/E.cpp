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
#define debugv(v)   //      \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m)              \
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

class Centroid
{
    graph Tree;
    vi d;
    vi p;
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
        Tree.resize(n);
        p.resize(n);
        rep(i, n) p[i] = -2;
        d.assign(n, -1);
        find_centroids(0, -1, g);
    }
    int parent(int u) { return p[u]; }
    int depth(int u) { return (d[u] != -1) ? d[u] : ((parent(u) == -1) ? d[u] = 0 : d[u] = depth(parent(u)) + 1); }
};

int main()
{
    int n;
    cin >> n;
    graph g(n);
    rep(_, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    Centroid T(g);

    rep(i, n) if (T.depth(i) >= 26)
    {
        cout << "Impossible!\n";
        return 0;
    }
    rep(i, n) cout << char(T.depth(i) + 'A') << ' ';
    cout << '\n';
}