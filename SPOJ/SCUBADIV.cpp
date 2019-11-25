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

struct cylinder
{
    int w, o, n; // Weight, Oxygen Vol, Nitrogen Vol
    cylinder(int w, int o, int n) : w(w), o(o), n(n) {}
};

vector<cylinder> cylinders;
vector<vector<vector<ll>>> DP;

ll func(int o, int n, int m)
{
    if (n == 0 and o == 0)
        return 0;
    if (m < 0)
        return 1e9;
    if (DP[o][n][m] != -1)
        return DP[o][n][m];

    ll ans = 1e9;
    if (m > 0)
    {
        ll temp = func(max(o - cylinders[m].o, 0), max(n - cylinders[m].n, 0), m - 1);
        if (temp != 1e9)
            ans = min(ans, temp + cylinders[m].w);
        ans = min(ans, func(o, n, m - 1));
    }
    else
        ans = cylinders[m].w + func(o - cylinders[m].o, n - cylinders[m].n, m - 1);
    return DP[o][n][m] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    rep(_, c)
    {
        int t, a; //Oxygen, Nitrogen
        cin >> t >> a;
        int n;
        cin >> n;
        cylinders.assign(n, {0, 0, 0});
        DP.assign(t + 1, vector<vector<ll>>(a + 1, vector<ll>(n, -1)));
        rep(i, n) cin >> cylinders[i].o >> cylinders[i].n >> cylinders[i].w;
        cout << func(t, a, n - 1) << '\n';
    }
}