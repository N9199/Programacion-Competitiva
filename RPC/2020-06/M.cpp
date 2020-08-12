#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) //        \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m) //             \
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

enum TYPE
{
    AIR,
    SEA,
    RAIL,
    TRUCK
};

struct p
{
    ll d;
    int index;
    TYPE type;
    p(ll d, int i, TYPE t) : d(d), index(i), type(t) {}

    bool operator<(const p &o) const
    {
        return d > o.d;
    }
};

std::ostream &operator<<(std::ostream &_os, const p &o)
{
    _os << "(" << o.d << ',' << o.index << ',' << o.type << ')';
    return _os;
}

ll dijsktra(int start, int end, vector<vector<p>> &g, vi &n)
{
    graph dist(g.size(), vi(4, 1e18));
    priority_queue<p> q;
    rep(i, 4)
    {
        dist[start][i] = 0;
        q.emplace(0, start, TYPE(i));
    }
    while (!q.empty())
    {
        p u = q.top();
        q.pop();
        debugx(u);
        for (auto v : g[u.index])
        {
            if (dist[u.index][u.type] + v.d + (u.type != v.type) * n[u.index] < dist[v.index][v.type])
            {
                debugx(v);
                dist[v.index][v.type] = dist[u.index][u.type] + v.d + (u.type != v.type) * n[u.index];
                q.emplace(dist[v.index][v.type], v.index, v.type);
            }
        }
    }
    ll ans = 1e18;
    rep(i, 4) ans = min(ans, dist[end][i]);
    debugv(dist[end]);
    return ans;
}

int main()
{
    unordered_map<string, TYPE> m;
    vector<string> asdf = {"AIR", "SEA", "RAIL", "TRUCK"};
    rep(i, 4) m[asdf[i]] = TYPE(i);
    int n;
    cin >> n;
    int c;
    rep(_, n)
    {
        cin >> c;
        unordered_map<string, int> a;
        vi cost(c);
        string temp;
        rep(i, c)
        {
            cin >> temp;
            a[temp] = i;
            cin >> cost[i];
        }
        vector<vector<p>> g(c);
        int r;
        cin >> r;
        string u, v;
        string t;
        ll w;
        debugv(m);
        rep(_, r)
        {
            cin >> u >> v >> t >> w;
            debugx(t);
            g[a[u]].eb(w, a[v], m[t]);
            g[a[v]].eb(w, a[u], m[t]);
        }
        debugm(g);
        debugv(a);
        cin >> u >> v;
        cout << dijsktra(a[u], a[v], g, cost) << '\n';
    }
}