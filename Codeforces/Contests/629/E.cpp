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

class LcaForest
{
    int n;
    vi level;
    vi root;
    graph P;

public:
    vi parent;
    LcaForest(int n)
    {
        this->n = n;
        parent.assign(n, -1);
        level.assign(n, -1);
        P.assign(n, vi(lg(n) + 1, -1));
        root.assign(n, -1);
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
    int lca(int u, int v)
    {
        if (root[u] != root[v] || root[u] == -1)
            return -1;
        if (level[u] < level[v])
            swap(u, v);
        int dist = level[u] - level[v];
        while (dist != 0)
        {
            int raise = lg(dist);
            u = P[u][raise];
            dist -= (1 << raise);
        }
        if (u == v)
            return u;
        for (int j = lg(n); j >= 0; --j)
        {
            if (P[u][j] != -1 && P[u][j] != P[v][j])
            {
                u = P[u][j];
                v = P[v][j];
            }
        }
        return parent[u];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    LcaForest F(n);
    graph g(n);
    int u, v;
    rep(_, m)
    {
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }

    F.addRoot(0);

    vi visited(n);
    stack<int> s;
    s.emplace(0);
    visited[0] = 1;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (auto v : g[u])
            if (not visited[v])
            {
                visited[v] = 1;
                s.emplace(v);
                F.addLeaf(v, u);
            }
    }
    int k;
    rep(_, m)
    {
        cin >> k;
        int curr = -1;
        int temp;
        bool flag = true;
        debugx(k);
        rep(__, k)
        {
            cin >> temp;
            temp--;
            debugx(make_pair(curr, temp));
            if (F.parent[temp] != 0 and flag)
                temp = F.parent[temp];
            else
                continue;
            
            if (curr < 0)
                curr = temp;
            else
            {
                int lca = F.lca(curr, temp);
                debugx(lca);
                if (lca != curr and lca != temp)
                    flag = false;
                else
                    curr = lca;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}