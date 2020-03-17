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

graph g;
map<par, int> val;

void visit(int u)
{
    if (g[u].size() == 1)
    {
        val[make_pair(u, g[u][0])] = g.size() - 1;
        val[make_pair(g[u][0], u)] = 1;
    }
    else
        for (int v : g[u])
        {
            if (v == u)
                continue;
            visit(v);
            for (int a : g[v])
            {
                if (a == v)
                    continue;
                val[make_pair(u, v)] += val[make_pair(v, a)];
            }
            val[make_pair(v, u)] = g.size() - val[make_pair(u, v)];
        }
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    vp order(n - 1);
    map<par, int> m;
    rep(i, n - 1)
    {
        cin >> order[i].first >> order[i].second;
        order[i].first--;
        order[i].second--;
        g[order[i].first].eb(order[i].second);
        g[order[i].second].eb(order[i].first);
        val[order[i]] = 0;
        val[make_pair(order[i].second, order[i].first)] = 0;
    }

    visit(0);

    vp ans(order);
    sort(ans.begin(), ans.end(), [&](par const &l, par const &r) { return abs(val[l] - val[make_pair(l.second, l.first)]) < abs(val[r] - val[make_pair(r.second, r.first)]); });
    debugv(ans);
    m[ans[0]] = 0;
    rep(i, n - 2)
    {
        m[ans[i + 1]] = n - 2 - i;
    }
    rep(i, n - 1)
    {
        cout << m[order[i]] << '\n';
    }
}