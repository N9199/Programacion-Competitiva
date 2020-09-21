#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
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
#define debugm(m)             \
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

class Dinic
{
    struct edge
    {
        int to, rev;
        ll f, cap;
    };

    vector<vector<edge>> g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;

    bool bfs(int start, int finish)
    {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail)
        {
            int u = q[head++];
            for (const edge &e : g[u])
            {
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap)
                {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }

    ll dfs(int u, ll f)
    {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i)
        {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if (df > 0)
            {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

public:
    Dinic(int n)
    {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }

    void add_edge(int u, int v, ll cap)
    {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0,
                  cap}; // Poner cap en vez de 0 si la arista es bidireccional
        g[u].pb(a);
        g[v].pb(b);
    }

    ll max_flow(int source, int dest)
    {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest))
        {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};

int r, c;
graph g;

const vii dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int col)
{
    g[x][y] = col;
    for (auto [dx, dy] : dirs)
        if (0 <= x + dx and x + dx < r and 0 <= y + dy and y + dy < c and g[x + dx][y + dy] == -1)
            dfs(x + dx, y + dy, col ^ 1);
}

int main()
{
    while (cin >> r >> c)
    {
        g.assign(r, vi(c, -1));
        char temp;
        rep(i, r) rep(j, c)
        {
            cin >> temp;
            g[i][j] -= (temp == 'X');
        }
        debugx("Hola");
        rep(i, r) rep(j, c) if (g[i][j] == -1) dfs(i, j, 1);
        vi count(2);
        rep(i, r) rep(j, c) if (g[i][j] > -1) count[g[i][j]]++;
        if (count[0] != count[1])
        {
        }
        debugm(g);
        Dinic d(count[0] + count[1] + 2); // [0,count[0]) zeroes, [count[0],count[0]+count[1]) ones, Source count[0]+count[1], Sink count[0]+count[1]+1
        vi count2(2);
        rep(i, r) rep(j, c) if (g[i][j] > -1)
        {
            if (i + 1 < r and g[i + 1][j] > -1)
            {
                d.add_edge(count2[g[i][j]] + g[i][j] * count[0], count2[g[i + 1][j]] + g[i + 1][j] * count[0], 1);
            }
            if (j + 1 < c and g[i][j + 1] > -1)
            {
                d.add_edge(count2[g[i][j]] + g[i][j] * count[0], count2[g[i][j + 1]] + g[i][j + 1] * count[0], 1);
            }
            d.add_edge(count2[g[i][j]] + g[i][j] * count[0], count[0] + count[1] + g[i][j], 1);
            count2[g[i][j]]++;
        }
    }
}