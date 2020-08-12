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
#define debugx(x) cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v)         \
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

struct tarjanSCC
{
    vector<int> _stack, ids, low;
    vector<bool> instack;
    vector<int> mark;
    vector<vector<int>> *g;
    int n, ID, C;
    void dfs(int u)
    {
        ids[u] = low[u] = ID++;
        instack[u] = true;
        _stack.push_back(u);
        for (int v : (*g)[u])
        {
            if (ids[v] == -1)
            {
                dfs(v);
                low[u] = min(low[v], low[u]);
            }
            else if (instack[v])
            {
                low[u] = min(low[v], low[u]);
            }
        }
        if (low[u] == ids[u])
        {
            // u is the root of a SCC
            // ** here you can do whatever you want
            // with the SCC just found
            // cout << "SCC found!\n";
            // remove SCC from top of the stack
            while (1)
            {
                int x = _stack.back();
                _stack.pop_back();
                mark[x] = C;
                instack[x] = false;
                if (x == u)
                    break;
            }
            C++;
        }
    }
    tarjanSCC(vector<vector<int>> &_g)
    {
        g = &_g;
        n = _g.size();
        _stack.reserve(n);
        ids.assign(n, -1);
        mark.assign(n, -1);
        low.resize(n);
        instack.assign(n, 0);
        ID = 0;
        C = 0;
        rep(u, n) if (ids[u] == -1) dfs(u);
    }
};

struct circle
{
    ll x, y, r;
    circle() : x(0), y(0), r(0) {}
};

struct point
{
    ll x, y, h;
    point() : x(0), y(0), h(0) {}
};

ll dist_sqr(const point &p, const circle &c)
{
    return (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y);
}

ll dist_sqr(const circle &p, const circle &c)
{
    return (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y);
}

bool reachable(const point &p, const circle &c, int k)
{
    return dist_sqr(p, c) <= (c.r + k * p.h) * (c.r + k * p.h);
}

bool dfs(int start, graph &g)
{
    vi visited(g.size());
    int count = 1;
    stack<int> s;
    s.emplace(start);
    visited[start] = 1;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (auto v : g[u])
            if (!visited[v])
            {
                visited[v] = 1;
                s.emplace(v);
                count++;
            }
    }

    return count == g.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Fix precision on cout
    cout.setf(ios::fixed);
    cout.precision(8);

    int n, m, k;
    cin >> n >> m >> k;
    vector<circle> c(n);
    rep(i, n) cin >> c[i].x >> c[i].y >> c[i].r;
    vector<point> p(m);
    rep(i, m) cin >> p[i].x >> p[i].y >> p[i].h;
    vi inCircle(m);
    rep(i, m) rep(j, n) if (dist_sqr(p[i], c[j]) <= c[j].r * c[j].r)
    {
        inCircle[i] = j;
        break;
    }
    graph g(n);
    rep(i, m) rep(j, n) if (reachable(p[i], c[j], k) and inCircle[i] != j) g[inCircle[i]].eb(j);

    debugm(g);
    debugv(inCircle);
    tarjanSCC G(g);
    debugx(G.C);
    debugv(G.mark);
    if (G.C > 2)
    {
        graph g1(G.C);
        graph g2(G.C);
        int node1 = -1, node2 = -1;
        rep(i, n) for (auto u : g[i]) if (G.mark[i] != G.mark[u]) g1[G.mark[i]].eb(G.mark[u]), g2[G.mark[u]].eb(G.mark[i]);
        debugm(g1);
        debugm(g2);
        vi visted(G.C);
        rep(i, G.C) if (g1[i].size() == 0 and dfs(i, g2)) node1 = i;
        else if (g2[i].size() == 0 and dfs(i, g1)) node2 = i;
        double ans = 1e12;
        rep(i, n) repx(j, i + 1, n) if (G.mark[j] == node1 and G.mark[i] == node2 and c[i].r >= 0 and c[j].r >= 0) ans = min(ans, sqrt(dist_sqr(c[i], c[j])) + 200 - c[i].r - c[j].r);
        if (ans < 1e12)
            cout << ans << '\n';
        else
            cout << "impossible\n";
    }
    else if (G.C == 2)
    {
        double ans = 1e12;
        rep(i, n) repx(j, i + 1, n) if (G.mark[j] != G.mark[i] and c[i].r >= 100 and c[j].r >= 100) ans = min(ans, sqrt(dist_sqr(c[i], c[j])) + 200 - c[i].r - c[j].r);
        cout << ans << '\n';
    }
    else
    {
        cout << "0\n";
    }
}