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

#define debugx(x) cerr << #x << ": " << x << endl
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
        edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
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

int main()
{
    int r, c;
    graph dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (cin >> r >> c)
    {
        char temp;
        int count = 0;
        int even = 0;
        int odd = 0;
        unordered_map<int, vi> a;

        rep(i, r) rep(j, c)
        {
            cin >> temp;
            if (temp == 'o')
            {
                if ((i + j) & 1)
                    even++;
                else
                    odd++;

                a[i + r * j] = {count++};
            }
            else
            {
                if ((i + j) & 1)
                    even += 2;
                else
                    odd += 2;

                a[i + r * j] = {count++, count++};
            }
        }
        if (odd != even)
        {
            cout << "N\n";
            continue;
        }
        int source = count;
        int target = count + 1;
        Dinic d(count + 2);
        rep(i, r) rep(j, c)
        {
            if ((i + j) & 1)
                for (auto dir : dirs)
                {
                    int rr = i + dir[0];
                    int cc = j + dir[1];
                    if (0 <= rr and rr < r and 0 <= cc and cc < c)
                    {
                        for (auto e : a[i + r * j])
                            for (auto e2 : a[rr + cc * r])
                                d.add_edge(e, e2, 1);
                    }
                }

            if ((i + j) & 1)
                for (auto e : a[i + r * j])
                    d.add_edge(source, e, 1);
            else
                for (auto e : a[i + r * j])
                    d.add_edge(e, target, 1);
        }
        int max_flow = d.max_flow(source, target);

        if (max_flow == even)
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}