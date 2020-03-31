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

#define lg(x) 31 - __builtin_clz(x)

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
    int c;
    cin >> c;
    rep(C, c)
    {
        int n;
        cin >> n;
        graph g(n);
        vi seen(n);
        rep(i, n)
        {
            int t;
            cin >> t;
            int temp;
            rep(_, t)
            {
                cin >> temp;
                temp--;
                g[i].eb(temp);
                seen[temp] = 1;
            }
        }
        LcaForest f(n);
        rep(i, n) if (!seen[i])
        {
            f.addRoot(i);
            stack<int> s;
            s.emplace(i);
            while (!s.empty())
            {
                int u = s.top();
                s.pop();
                for (auto v : g[u])
                {
                    f.addLeaf(v, u);
                    s.emplace(v);
                }
            }
        }
        int q;
        cin >> q;
        cout << "Case " << C + 1 << ":\n";
        rep(_, q)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            cout << f.lca(u, v) + 1 << '\n';
        }
    }
}