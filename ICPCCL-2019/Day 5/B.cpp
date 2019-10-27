#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int bfs(graph &g, int start)
{
    int n = g.size();
    vi visited(n, 1);
    queue<int> q;

    q.emplace(start);
    visited[start] = 0;
    while (not q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (visited[v])
            {
                q.emplace(v);
                visited[v] = 0;
            }
        }
    }
    rep(i, n)
    {
        if (visited[i])
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if (m != n - 1)
    {
        cout << "no\n";
        return 0;
    }
    graph g(n);
    int a, b;
    rep(i, m)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].eb(b);
        g[b].eb(a);
    }
    if (bfs(g, 0))
    {
        cout << "yes\n";
    }else
    {
        cout << "no\n";
    }
}

