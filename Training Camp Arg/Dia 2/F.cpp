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

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m) //            \
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
const int MOD = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    graph dp(n + 2, vi(k + 2, 0));
    rep(i, n + 1)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    debugm(dp);

    rep(i, k + 1) dp[0][i] = 0;
    debugm(dp);

    repx(j, 1, k) repx(i, 1, n + 1) for (int d = i; d < n + 1; d += i)
    {
        dp[d][j + 1] += dp[i][j];
        dp[d][j + 1] %= MOD;
    }
    debugm(dp);

    int ans = 0;
    rep(i, n+1)
    {
        ans += dp[i][k];
        ans %= MOD;
    }
    cout << ans << '\n';
}