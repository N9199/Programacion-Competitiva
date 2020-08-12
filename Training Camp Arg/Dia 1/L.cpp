#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
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

const int INF = 1200 * 1000 + 2;
int dp[600][300][300];
int w[300][300];
int func(int d, int c1, int c2)
{
    if (dp[d][c1][c2] != -INF)
        return dp[d][c1][c2];
    int ans = -INF + 1;
    if (c1 > 0 and c2 > 0)
        ans = max(ans, func(d - 1, c1 - 1, c2 - 1));
    if (c1 > 0 and c2 <= d - 1)
        ans = max(ans, func(d - 1, c1 - 1, c2));
    if (c2 > 0 and c1 <= d - 1)
        ans = max(ans, func(d - 1, c1, c2 - 1));
    if (c1 <= d - 1 and c2 <= d - 1)
        ans = max(ans, func(d - 1, c1, c2));
    if (c1 != c2)
        ans += w[c1][d - c1];
    ans += w[c2][d - c2];
    return dp[d][c1][c2] = ans;
}

int32_t main()
{
    int n;
    cin >> n;
    rep(i, 2 * n - 1) rep(j, n) rep(k, n) dp[i][j][k] = -INF;
    rep(i, n) rep(j, n) cin >> w[i][j];
    dp[0][0][0] = w[0][0];
    cout << func(2 * n - 2, n - 1, n - 1) << '\n';
}