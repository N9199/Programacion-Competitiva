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
const int ms = 501;
const int inf = 1e9;

int u[ms], v[ms], p[ms], way[ms], minv[ms];
bool used[ms];

pair<vector<int>, int> solve(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return {vector<int>(), 0};
    int m = matrix[0].size();
    assert(n <= m);
    memset(u, 0, (n + 1) * sizeof(int));
    memset(v, 0, (m + 1) * sizeof(int));
    memset(p, 0, (m + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        memset(minv, 0x3f, (m + 1) * sizeof(int));
        memset(way, 0, (m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++)
            used[j] = 0;
        p[0] = i;
        int k0 = 0;
        do
        {
            used[k0] = 1;
            int i0 = p[k0], delta = inf, k1;
            for (int j = 1; j <= m; j++)
            {
                if (!used[j])
                {
                    int cur = matrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = k0;
                    }
                    if (minv[j] < delta)
                    {
                        delta = minv[j];
                        k1 = j;
                    }
                }
            }
            for (int j = 0; j <= m; j++)
            {
                if (used[j])
                {
                    u[p[j]] += delta;
                    v[j] -= delta;
                }
                else
                {
                    minv[j] -= delta;
                }
            }
            k0 = k1;
        } while (p[k0]);
        do
        {
            int k1 = way[k0];
            p[k0] = p[k1];
            k0 = k1;
        } while (k0);
    }
    vector<int> ans(n, -1);
    for (int j = 1; j <= m; j++)
    {
        if (!p[j])
            continue;
        ans[p[j] - 1] = j - 1;
    }
    return {ans, -v[0]};
}

int main()
{
    int n;
    cin >> n;
    graph g(n);
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    rep(i, n) repx(j, i + 1, n)
    {
        int c = 0;
        rep(k, n) if (s[i][k] != s[j][k]) c++;
        if (c == 2)
        {
            g[i].eb(j);
            g[j].eb(i);
        }
    }
    vi col(n, -1);
    vi vis(n);
    queue<int> q;
    rep(i, n) if (vis[i] == 0)
    {
        q.emplace(i);
        vis[i] = 1;
        col[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
                if (vis[v] == 0)
                {
                    col[v] = 1 - col[u];
                    vis[v] = 1;
                    q.emplace(v);
                }
        }
    }
    int ans = 0;
    vis.assign(n, 0);
    vi c(2);
    rep(i, n) if (vis[i] == 0)
    {
        debugv(vis);
        c[0] = c[1] = 0;
        q.emplace(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            c[col[u]]++;
            for (auto v : g[u])
                if (vis[v] == 0)
                {
                    vis[v] = 1;
                    q.emplace(v);
                }
        }
        ans += max(c[0], c[1]);
    }
    cout << ans << '\n';
    debugm(g);
}