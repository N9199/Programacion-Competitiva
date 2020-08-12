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

vi dp;
vii r;
ll func(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int j = lower_bound(r.begin(), r.end(), ii(r[i].second + 1, 0)) - r.begin();
    return dp[i] = max(func(j) + 1, func(i + 1));
}

int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    r.resize(n);
    dp[n] = 0;
    rep(i, n) cin >> r[i].first >> r[i].second;
    sort(r.begin(), r.end());
    cout << func(0) << '\n';
}