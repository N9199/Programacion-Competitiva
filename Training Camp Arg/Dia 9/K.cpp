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

#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugv(v) //        \
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
const int N = (int)1e4 + 1;
char dp1[N][N];
short dp2[N][N];
char style1[N];
char style2[N];
short s[N];
int n, m;
char func1(int i, int j, graph &g1, graph &g2)
{
    if (dp1[i][j] != 'a')
        return dp1[i][j];
    debugx(2);
    debugx(ii(i, j));
    if (g1[i].size() != g2[j].size())
        return dp1[i][j] = 'c';
    if (style1[i] != style2[j])
        return dp1[i][j] = 'c';
    dp1[i][j] = 'b';
    rep(k, g1[i].size()) if (func1(g1[i][k], g2[j][k], g1, g2) == 'c')
    {
        dp1[i][j] = 'c';
        break;
    }
    return dp1[i][j];
}

short func2(int i, int j, graph &g1, graph &g2)
{
    if (dp2[i][j] != -1)
        return dp2[i][j];
    debugx(2);
    debugx(ii(i, j));
    if (func1(i, j, g1, g2) == 'b')
        return dp2[i][j] = s[i];
    debugx(ii(i, j));
    dp2[i][j] = 0;
    debugx("g1[i]xg2[j]");
    for (auto u1 : g1[i])
        for (auto u2 : g2[j])
            dp2[i][j] = max(dp2[i][j], func2(u1, u2, g1, g2));
    debugx("ixg2[j]");
    for (auto u2 : g2[j])
        dp2[i][j] = max(dp2[i][j], func2(i, u2, g1, g2));
    debugx("g1[i]xj");
    for (auto u1 : g1[i])
        dp2[i][j] = max(dp2[i][j], func2(u1, j, g1, g2));
    debugx(ii(i, j));
    return dp2[i][j];
}

short func(int u, graph &g)
{
    if (s[u] != -1)
        return s[u];
    s[u] = 1;
    for (auto v : g[u])
        s[u] += func(v, g);
    return s[u];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    rep(_, t)
    {
        cin >> n >> m;
        memset(dp1, 'a', sizeof(dp1));

        memset(dp2, -1, sizeof(dp2));
        memset(s, -1, sizeof(s));
        graph g1(n);
        graph g2(m);
        int temp;
        rep(i, n)
        {
            cin >> style1[i] >> temp;
            if (temp != -1)
                g1[temp].eb(i);
        }
        rep(i, m)
        {
            cin >> style2[i] >> temp;
            if (temp != -1)
                g2[temp].eb(i);
        }
        debugx("?");
        func(0, g1);
        debugx("?");

        cout << func2(0, 0, g1, g2) << '\n';

    }
}