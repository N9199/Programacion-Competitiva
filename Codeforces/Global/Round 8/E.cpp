#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        graph g(n);
        graph cg(n);
        rep(_, m)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            cg[v].eb(u);
        }
        queue<int> q;
        vi visited(n, -1);
        rep(i, n) if (cg[i].size() == 0)
        {
            q.emplace(i);
            visited[i] = 0;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
                if (visited[v] == -1)
                {
                    q.emplace(v);
                    visited[v] = (visited[u] + 1) % 3;
                }
        }
        vi c(3);
        rep(i, n) c[visited[i]]++;
        int ans = 0,index=-1;
        rep(i, 3) if (c[i] > ans) ans = c[i], index = i;
        //debugx(ans);
        //debugx(index);
        cout << ans << '\n';
        rep(i, n) if (visited[i] == index) cout << i + 1 << ' ';
        cout << '\n';
    }
}