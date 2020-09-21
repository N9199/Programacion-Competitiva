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
int deg[(int)1e5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    set<par> s;
    while (cin >> n >> m >> a >> b)
    {
        graph g(n);
        int u, v;
        rep(_, m)
        {
            cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            g[v].eb(u);
        }
        int c = 0;
        bool flag = false;
        rep(i, n) deg[i] = g[i].size(), s.emplace(deg[i], i);
        while (!s.empty())
        {
            flag = false;
            auto curr = *s.begin();
            if (curr.first < a)
            {
                for (auto u : g[curr.second])
                {
                    s.erase(par(deg[u], u));
                    deg[u]--;
                    if (deg[u] > 0)
                        s.emplace(deg[u], u);
                }
                s.erase(curr);
                deg[curr.second] = 0;
            }
            else
                flag = true;
            if (s.empty())
                break;
            curr = *s.rbegin();
            if (curr.first >= s.size() - b)
            {
                for (auto u : g[curr.second])
                {
                    s.erase(par(deg[u], u));
                    deg[u]--;
                    if (deg[u] > 0)
                        s.emplace(deg[u], u);
                }
                s.erase(curr);
                deg[curr.second] = 0;
            }
            else if (flag)
                c++;

            if (c == 2)
                break;
        }
        cout << s.size() << '\n';
        s.clear();
    }
}