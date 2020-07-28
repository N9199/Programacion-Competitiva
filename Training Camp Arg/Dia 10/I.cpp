#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back
#define gcd __gcd

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

#define ff first
#define ss second

template <class T>
class MCMF
{
    typedef pair<T, T> pTT;
    T INF = numeric_limits<T>::max();
    struct Edge
    {
        int v;
        T c, w;
        Edge(int v, T c, T w) : v(v), c(c), w(w) {}
    };

    int n;
    vector<vector<int>> E;
    vector<Edge> L;
    vector<int> F;
    vector<T> D, P;
    vector<bool> V;

    bool dij(int s, int t)
    {
        D.assign(n, INF);
        F.assign(n, -1);
        V.assign(n, false);
        D[s] = 0;
        rep(_, n)
        {
            int best = -1;
            rep(i, n) if (!V[i] && (best == -1 || D[best] > D[i])) best = i;
            if (D[best] >= INF)
                break;
            V[best] = true;
            for (int e : E[best])
            {
                Edge ed = L[e];
                if (ed.c == 0)
                    continue;
                T toD = D[best] + ed.w + P[best] - P[ed.v];
                if (toD < D[ed.v])
                    D[ed.v] = toD, F[ed.v] = e;
            }
        }
        return D[t] < INF;
    }

    pTT augment(int s, int t)
    {
        pTT flow(L[F[t]].c, 0);
        for (int v = t; v != s; v = L[F[v] ^ 1].v)
            flow.ff = min(flow.ff, L[F[v]].c), flow.ss += L[F[v]].w;
        for (int v = t; v != s; v = L[F[v] ^ 1].v)
            L[F[v]].c -= flow.ff, L[F[v] ^ 1].c += flow.ff;
        return flow;
    }

public:
    MCMF(int n) : n(n), E(n), D(n), P(n, 0), V(n, 0) {}

    pTT mcmf(int s, int t)
    {
        pTT ans(0, 0);
        if (!dij(s, t))
            return ans;
        rep(i, n) if (D[i] < INF) P[i] += D[i];
        while (dij(s, t))
        {
            auto flow = augment(s, t);
            ans.ff += flow.ff, ans.ss += flow.ff * flow.ss;
            rep(i, n) if (D[i] < INF) P[i] += D[i];
        }
        return ans;
    }

    void addEdge(int u, int v, T c, T w)
    {
        E[u].push_back(L.size());
        L.emplace_back(v, c, w);
        E[v].push_back(L.size());
        L.emplace_back(u, 0, -c);
    }
};
bool answerable = true;
void fill(int u, int p, vi &tree, graph &g)
{
    tree[u] = p;
    for (auto v : g[u])
        if (v != p)
            fill(v, u, tree, g);
}

int fix(int u, int p, graph &g, vi &d)
{
    int ans = 0;
    for (auto v : g[u])
        if (v != p)
        {
            ans += fix(v, u, g, d);
        }
    if (d[u] == 0)
        return ans;
    else
    {
        d[u] -= ans;
        if (d[u] < 0)
            answerable = false;
        return d[u] + ans;
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vi tree1(n, -1);
    vi tree2(n, -1);
    graph g1(n);
    graph g2(n);
    vi d1(n);
    vi d2(n);
    vi cost(n);
    debugx(1);
    rep(i, n) cin >> cost[i];
    debugx(2);
    rep(_, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g1[u].eb(v);
        g1[v].eb(u);
    }
    rep(_, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g2[u].eb(v);
        g2[v].eb(u);
    }
    debugx(3);
    int q;
    cin >> q;
    rep(_, q)
    {
        int u, c;
        cin >> u >> c;
        u--;
        d1[u] += c;
    }
    cin >> q;
    rep(_, q)
    {
        int u, c;
        cin >> u >> c;
        u--;
        d2[u] += c;
    }
    debugx(4);
    fill(x, -1, tree1, g1);
    fill(y, -1, tree2, g2);
    debugx(5);
    fix(x, -1, g1, d1);
    fix(y, -1, g2, d2);
    MCMF<ll> Bip(2 * n + 2);
    rep(i, n)
    {
        if (d1[i])
            Bip.addEdge(2 * n, i, d1[i], 0);
        if (d2[i])
            Bip.addEdge(i + n, 2 * n + 1, d2[i], 0);
    }
    debugx(6);
    // Not sure about this
    rep(u, n)
    {
        for (auto v : g1[u])
            if (v != tree1[u])
            {
                Bip.addEdge(u, v + n, 1e8, -cost[u]);
            }
        for (auto v : g2[u])
            if (v != tree2[u])
            {
                Bip.addEdge(u + n, v, 1e8, -cost[u]);
            }
        //Bip.addEdge(u, u + n, 1, -cost[u]);
    }
    debugx(7);
    // Back to being sure
    if (answerable)
    {
        auto ans = Bip.mcmf(2 * n, 2 * n + 1);
        cout << ans << '\n';
    }
    else
        cout << "-1\n";
}