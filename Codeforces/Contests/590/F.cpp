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

vi dp(1 << 20, -1);
int func(int b)
{
    if (dp[b] != -1)
        return dp[b];
    int ans = 0;
    rep(i, 20) if (b & (1 << i)) ans = max(ans, func(b & (~(1 << i))));
    return dp[b] = ans;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vi a(n);
    rep(i, n) a[i] = (1 << (s[i] - 'a'));
    vi b;
    b.reserve(1 << 21);
    dp[0] = 0;
    repx(k, 1, 21) rep(i, n - k + 1)
    {
        int temp = 0;
        bool flag = true;
        repx(j, i, i + k) if (flag &= !(temp & a[j])) temp |= a[j];
        if (flag)
        {
            b.eb(temp);
            dp[temp] = k;
        }
    }
    b.shrink_to_fit();
    //debugv(dp);
    int ans = 0;
    rep(i, b.size()) ans = max(ans, func(b[i]) + func(((1 << 20) - 1) & ~b[i]));
    cout << ans << '\n';
    return 0;
}
