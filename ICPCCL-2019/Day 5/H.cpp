#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
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

#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugv(v)  //      \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //                                  \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //                                                                            \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

vector<vector<int>> marked;
wgraph g;
wgraph g2;
void dfs(int start, int end, vi &cost, int total)
{
    for (auto i : g2[end])
    {
        if (cost[i.second] + i.first == cost[end])
        {
            marked[i.second][end] = 1;
            dfs(start, i.second, cost, total - i.first);
        }
    }
}

//g has vectors of pairs of the form (w, index)
int dijsktra2(int start, int end)
{
    int n = g.size();
    vi cost(n, 1e9); //~INT_MAX/2
    priority_queue<par, vp, greater<par>> q;

    q.emplace(0, start);
    cost[start] = 0;
    while (not q.empty())
    {
        int u = q.top().second, w = q.top().first;
        q.pop();

        // we skip all nodes in the q that we have discovered before at a lower cost
        if (cost[u] < w)
            continue;

        for (auto v : g[u])
        {
            if (cost[v.second] > v.first + w and marked[u][v.second] == 0)
            {
                cost[v.second] = v.first + w;
                q.emplace(cost[v.second], v.second);
            }
        }
    }
    return cost[end];
}

//g has vectors of pairs of the form (w, index)
void dijsktra(int start, int end)
{
    int n = g.size();
    vi cost(n, 1e9); //~INT_MAX/2
    priority_queue<par, vp, greater<par>> q;

    q.emplace(0, start);
    cost[start] = 0;
    while (not q.empty())
    {
        int u = q.top().second, w = q.top().first;
        q.pop();

        // we skip all nodes in the q that we have discovered before at a lower cost
        if (cost[u] < w)
            continue;

        for (auto v : g[u])
        {
            if (cost[v.second] > v.first + w)
            {
                cost[v.second] = v.first + w;
                q.emplace(cost[v.second], v.second);
            }
        }
    }
    if (cost[end] == 1e9)
    {
        cout << "-1\n";
        return;
    }
    dfs(start, end, cost, cost[end]);
    int ans = dijsktra2(start, end);
    if (ans == 1e9)
        cout << "-1\n";
    else
        cout << ans << "\n";
}

int n, m, s, d, u, v, p;

int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 and m == 0)
            break;
        cin >> s >> d;
        g.assign(n, vp());
        g2.assign(n, vp());
        marked.assign(n, vi(n, 0));
        rep(i, m)
        {
            cin >> u >> v >> p;
            g[u].eb(p, v);
            g2[v].eb(p, u);
        }
        dijsktra(s, d);
    }
}