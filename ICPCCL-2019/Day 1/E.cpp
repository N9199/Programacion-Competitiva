#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //\
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

const ll mod = (ll)1e9 + 7;

ll gcdext(ll a, ll b, ll &x, ll &y)
{
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1)
    {
        q = r2 / r1;
        r0 = r2 % r1;
        x0 = x2 - q * x1;
        y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;
    }
    ll g = r2;
    x = x2, y = y2;
    if (g < 0)
        g = -g, x = -x, y = -y;
    return g;
}

ll modularInverse(ll n, ll mod)
{
    ll x, y;
    ll g = gcdext(n, mod, x, y);
    return ((x + mod) % mod);
}

vi Factorial;
ll inline choose(int n, int k)
{
    return (Factorial[n] * modularInverse((Factorial[k] * Factorial[n - k]) % mod, mod)) % mod;
}

bool isGood(int n, int a, int b)
{
    while (n > 0)
    {
        int d = n % 10;
        if (d != a and d != b)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, n;
    cin >> a >> b >> n;
    Factorial.assign((int)1e6 + 1, -1);
    Factorial[0] = 1;
    repx(i, 1, (int)1e6 + 1)
    {
        Factorial[i] = (Factorial[i - 1] * (ll)i);
        Factorial[i] %= mod;
    }
    ll ans = 0;
    rep(k, n + 1)
    {
        if (isGood(k * a + (n - k) * b, a, b))
        {
            ans += choose(n, k);
            ans %= mod;
        }
    }
    cout << ans << '\n';
}