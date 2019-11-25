#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vii> wgraph;
typedef vector<vi> graph;
typedef vector<vll> vvll;

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

vvll accum_balls;

vector<vector<ll>> dp;

int n;

ll func(int i, int j)
{
    if (i + j >= n)
        return 0;

    if (dp[i][j] != -1e9)
        return dp[i][j];

    return dp[i][j] = max(accum_balls[i][j] + func(max(i - 1, 0), j + 1), func(i + 1, j));
}

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            return n;
        dp.assign(n, vll(n, -1e9));
        accum_balls.assign(n, vll(n, 0));
        rep(i, n) rep(j, i + 1)
        {
            cin >> accum_balls[n - i - 1][j];
            if (i != j)
            {
                accum_balls[n - i - 1][j] = accum_balls[n - i - 1][j] + accum_balls[n - i][j];
            }
        }

        cout << func(0, 0) << '\n';
    }
}