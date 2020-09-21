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

int n;
graph accum(2);
vll dp(1e5);
ll func(int i)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        fill(dp.begin(), dp.end(), -1);
        graph vals(2);
        vals[0] = vi(n - n / 2 + 1);
        vals[1] = vi(n - n / 2 + 1);
        accum[0] = vi(n - n / 2 + 2);
        accum[1] = vi(n - n / 2 + 2);
        rep(i, n) cin >> vals[i % 2][i / 2];
        rep(i, n + n % 2 + 2)
        {
            accum[i % 2][i / 2 + 1] += vals[i % 2][i / 2];
            accum[i % 2][i / 2 + 1] += accum[i % 2][i / 2];
        }
    }
}