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

vector<ll> coins;
vector<vector<ll>> DP;

ll func(int n, int m)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (m <= 0 and n > 0)
        return 0;
    if (DP[n][m] != -1)
        return DP[n][m];
    return DP[n][m] = func(n, m - 1) + func(n - coins[m - 1], m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    DP.assign(n + 1, vector<ll>(m + 1, -1));
    coins.assign(m, 0);
    rep(i, m) cin >> coins[i];
    cout << func(n, m) << '\n';
}