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

bool dfs(int i, int col, vi &visited, graph &g)
{
    visited[i] = col;
    for (auto k : g[i])
    {
        if (visited[k] != -1)
        {
            if (visited[k] == col)
                return false;
        }
        else if (!dfs(k, 1 - col, visited, g))
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    rep(tt, t)
    {
        cout << "Scenario #" << tt + 1 << ":\n";
        int n, m;
        cin >> n >> m;
        graph g(n, vi(0));
        vi visited(n, -1);
        rep(i, m)
        {
            int a, b;
            cin >> a >> b;
            g[a - 1].eb(b - 1);
            g[b - 1].eb(a - 1);
        }
        bool nice = true;
        rep(i, n)
        {
            if (visited[i] == -1)
            {
                if (!dfs(i, 0, visited, g))
                {
                    nice = false;
                    break;
                }
            }
        }
        if (!nice)
        {
            cout << "Suspicious bugs found!\n\n";
        }
        else
        {
            cout << "No suspicious bugs found!\n\n";
        }
    }
}