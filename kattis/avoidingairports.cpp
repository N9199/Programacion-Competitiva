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

#define ff first
#define ss second

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
struct edge
{
    int v;
    ll s, e;
    edge(int v, ll s, ll e) : v(v), s(s), e(e) {}
};

struct node
{
    int v;
    ll w, c;
    node(int v, ll w, ll c) : v(v), w(w), c(c) {}
    bool operator<(const node &o) const { return w > o.w; }
};
vector<vector<edge>> g;
vector<ll> d;
ll dijsktra(int start, int end)
{
    priority_queue<node> q;
    q.emplace(start, 0, 0);
    d[start] = 0;
    while (!q.empty())
    {
        auto u = q.top();
        q.pop();
        debugx(u.v);
        debugx(u.c);
        debugx(u.w);
        for (auto v : g[u.v])
        {
            debugx(v.s);
            debugx(v.v);
            if (u.c <= v.s and d[v.v] > u.w + (v.s - u.c) * (v.s - u.c))
            {
                debugx("??");
                d[v.v] = u.w + (v.s - u.c) * (v.s - u.c);
                q.emplace(v.v, d[v.v], v.e);
            }
        }
    }
    return d[end];
}

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    d.assign(n, 1e18);
    rep(_,m){
        int u, v;
        ll s, e;
        cin >> u >> v >> s >> e;
        u--, v--;
        g[u].eb(v, s, e);
        debugx(ii(u, v));
    }
    cout << dijsktra(0, n - 1) << '\n';
    debugv(d);
}