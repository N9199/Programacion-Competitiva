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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto &v : m)         \
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

const int MAXN = 11;
int cost[MAXN][MAXN];
int memo[1 << MAXN][MAXN]; // 2^MAXN x MAXN
int dp(int mask, int i)
{
    // base case 1: problem already solved
    int &ans = memo[mask][i];
    if (ans != -1)
        return ans;

    // mark i-th node as visited
    int mask2 = mask & ~(1 << i);

    // base case 2: nothing else to visit
    if (mask2 == 0)
        return ans = 0;
    // if (mask2 == 0) return ans = cost[i][start_index]; // <--- if returning back to start

    // general case: try all possible next nodes
    ans = INT_MAX;
    for (int j = 0, tmp = mask2; tmp; ++j, tmp >>= 1)
    {
        if (tmp & 1)
            ans = min(ans, cost[i][j] + dp(mask2, j));
    }

    // return best answer
    return ans;
}

struct iii
{
    int x, y, d;
    iii(int x, int y, int d) : x(x), y(y), d(d) {}
};

int h, w;

vii dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfs(graph g, int i, int j)
{
    queue<iii> q;
    q.emplace(i, j, 0);
    int t = g[i][j];
    cost[t - 1][t - 1] = 0;
    g[i][j] = -1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto d : dirs)
        {
            int x = u.x + d.first, y = u.y + d.second;
            if (x < h and x >= 0 and y < w and y >= 0 and g[x][y] >= 0)
            {
                q.emplace(x, y, u.d + 1);
                if (g[x][y] > 0)
                {
                    cost[t - 1][g[x][y] - 1] = cost[g[x][y] - 1][t - 1] = u.d + 1;
                }
                g[x][y] = -1;
            }
        }
    }
}

int main()
{
    while (cin >> w >> h)
    {
        if (h == 0)
            return 0;
        graph g(h, vi(w, -1));
        vii d;
        int rx, ry;
        int k = 1;
        rep(i, h) rep(j, w)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case '.':
                g[i][j] = 0;
                break;
            case '*':
                g[i][j] = ++k;
                d.eb(i, j);
                break;
            case 'o':
                rx = i, ry = j;
                g[i][j] = 1;
                break;

            default:
                break;
            }
        }
        memset(memo, -1, sizeof memo);
        memset(cost, -1, sizeof cost);
        bfs(g, rx, ry);
        for (auto s : d)
        {
            bfs(g, s.first, s.second);
        }
        bool flag = true;
        rep(i, k) repx(j, i + 1, k) if (cost[i][j] == -1) flag = false;

        if (flag)
        {
            int ans = dp((1 << k) - 1, 0);
            ans = (ans < 0) ? -1 : ans;
            cout << ans << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }
}