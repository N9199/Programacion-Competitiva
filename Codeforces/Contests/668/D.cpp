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
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)
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

graph Tree;
vi dist;

// Finds a diameter node
int bfs1()
{
    int n = Tree.size();
    queue<int> q;

    q.emplace(0);
    dist[0] = 0;
    int u;
    while (not q.empty())
    {
        u = q.front();
        q.pop();

        for (int v : Tree[u])
        {
            if (dist[v] == -1)
            {
                q.emplace(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return u;
}

// Fills the distances from one diameter node and finds another diameter node
int bfs2()
{
    int n = Tree.size();
    vi visited(n, 1);
    queue<int> q;
    int start = bfs1();
    q.emplace(start);
    visited[start] = 0;
    int u;
    while (not q.empty())
    {
        u = q.front();
        q.pop();

        for (int v : Tree[u])
        {
            if (visited[v])
            {
                q.emplace(v);
                visited[v] = 0;
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }
    }
    return u;
}

// Finds the diameter
int bfs3()
{
    int n = Tree.size();
    vi visited(n, 1);
    queue<int> q;
    int start = bfs2();
    q.emplace(start);
    visited[start] = 0;
    int u;
    while (not q.empty())
    {
        u = q.front();
        q.pop();

        for (int v : Tree[u])
        {
            if (visited[v])
            {
                q.emplace(v);
                visited[v] = 0;
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }
    }
    return dist[u];
}

int main()
{
    int t;
    cin >> t;
    int n, a, b, da, db;
    int u, v;
    rep(_, t)
    {
        cin >> n >> a >> b >> da >> db;
        Tree.clear();
        dist.assign(n, 0);
        Tree.resize(n);
        rep(i, n - 1)
        {
            cin >> u >> v;
            u--;
            v--;
            Tree[u].eb(v);
            Tree[v].eb(u);
        }
        int d = bfs3();
        if (db < da or (db>=da and d<=da))
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
        }
}