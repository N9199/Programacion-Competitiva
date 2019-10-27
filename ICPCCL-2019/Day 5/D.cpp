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

int m, n;

int bfs(vector<vector<char>> &g, int x, int y, char c)
{
    queue<par> q;
    int ans = 0;
    q.emplace(x, y);
    vp dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    if(g[x][y] == c)
        ans++;
    g[x][y] = c - 1;
    while (not q.empty())
    {
        par u = q.front();
        q.pop();

        for (par d : dirs)
        {
            if (u.first + d.first >= 0 and u.first + d.first < m)
                if (g[u.first + d.first][(u.second + d.second + n) % n] == c)
                {
                    q.emplace(u.first + d.first, (u.second + d.second + n) % n);
                    g[u.first + d.first][(u.second + d.second + n) % n] = c - 1;
                    ans++;
                }
        }
    }
    return ans;
}

int main()
{
    while (cin >> m >> n)
    {
        vector<vector<char>> g(m, vector<char>(n, '0'));
        rep(i, m) rep(j, n)
        {
            cin >> g[i][j];
        }
        int x, y;
        cin >> x >> y;
        char c = g[x][y];

        bfs(g, x, y, c);
        int ans = 0;
        rep(i, m) rep(j, n)
        {
            ans = max(ans, bfs(g, i, j, c));
        }
        cout << ans << '\n';
    }
}