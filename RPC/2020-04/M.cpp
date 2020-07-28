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
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

void dfs(int x, int y, graph &g)
{
    g[x][y] = 1;
    rep(i, 4) if (g[x + dx[i]][y + dy[i]] != 1) dfs(x + dx[i], y + dy[i], g);
}

int main()
{
    int r, c;
    cin >> r >> c;
    graph g(2 * r + 4, vi(2 * c + 4));
    char in;
    rep(i, 2 * r + 4) g[i][0] = g[i][2 * c + 3] = 1;
    rep(i, 2 * c + 4) g[0][i] = g[2 * r + 3][i] = 1;
    rep(i, r) rep(j, c)
    {
        cin >> in;
        if (in == '/')
        {
            g[2 + 2 * i + 1][2 + 2 * j] = 1;
            g[2 + 2 * i][2 + 2 * j + 1] = 1;
        }
        else if (in == '\\')
        {
            g[2 + 2 * i][2 + 2 * j] = 1;
            g[2 + 2 * i + 1][2 + 2 * j + 1] = 1;
        }
    }
    int ans = 0;
    dfs(1, 1, g);
    rep(i, 2 * r + 4) rep(j, 2 * c + 4) if (g[i][j] != 1)
    {
        dfs(i, j, g);
        ans++;
    }
    cout << ans << '\n';
}