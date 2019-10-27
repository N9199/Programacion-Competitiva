#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
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

#define debugx(x) //cerr << #x << ": " << x << endl
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

ll inline mod(ll x, ll m) { return ((x %= m) < 0) ? x + m : x; }
ll inline mul(ll x, ll y, ll m) { return (x * y) % m; }
ll inline add(ll x, ll y, ll m) { return (x + y) % m; }

ll mulmod(ull a, ull b, ull c)
{
    ull x = 0, y = a % c;
    while (b)
    {
        if (b & 1)
            x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1)
            ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret;
}

// extended euclidean algorithm
// finds g, x, y such that
//    a * x + b * y = g = GCD(a,b)
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
        g = -g, x = -x, y = -y; // make sure g > 0
    // for debugging (in case you think you might have bugs)
    // assert (g == a * x + b * y);
    // assert (g == __gcd(abs(a),abs(b)));
    return g;
}

// ==============================================
// CRT for a system of 2 modular linear equations
// ==============================================
// We want to find X such that:
//   1) x = r1 (mod m1)
//   2) x = r2 (mod m2)
// The solution is given by:
//    sol = r1 + m1 * (r2-r1)/g * x' (mod LCM(m1,m2))
// where x' comes from
//   m1 * x' + m2 * y' = g = GCD(m1,m2)
//   where x' and y' are the values found by extended euclidean algorithm (gcdext)
// Useful references:
//   https://codeforces.com/blog/entry/61290
//   https://forthright48.com/chinese-remainder-theorem-part-1-coprime-moduli
//   https://forthright48.com/chinese-remainder-theorem-part-2-non-coprime-moduli
// ** Note: this solution works if lcm(m1,m2) fits in a long long (64 bits)
pair<ll, ll> CRT(ll r1, ll m1, ll r2, ll m2)
{
    ll g, x, y;
    g = gcdext(m1, m2, x, y);
    if ((r1 - r2) % g != 0)
        return {-1, -1}; // no solution
    ll z = m2 / g;
    ll lcm = m1 * z;
    ll sol = add(mod(r1, lcm), m1 * mul(mod(x, z), mod((r2 - r1) / g, z), z), lcm);
    // for debugging (in case you think you might have bugs)
    // assert (0 <= sol and sol < lcm);
    // assert (sol % m1 == r1 % m1);
    // assert (sol % m2 == r2 % m2);
    return {sol, lcm}; // solution + lcm(m1,m2)
}

vii MOD = {{3, 3}, {11, 1}, {13, 1}, {37, 1}}; //142857 = 3^3*11*13*37
/* Precomputed Factorials and their inverse, in case of prime powers, it's the factorial without factors divisible by the prime */
vector<vector<ll>> FMOD(4);
vector<vector<ll>> invFMOD(4);

ll lucas(ll n, ll r, ll m)
{
    if (r > n)
        return 0;
    if (r == 0 or n == r)
        return 1;
    if (r == 1 or r == n - 1)
        return n % MOD[m].first;
    if (n < MOD[m].first and r < MOD[m].first)
    {
        ll ans = mul(FMOD[m][n], invFMOD[m][r], MOD[m].first);
        ans = mul(ans, invFMOD[m][n - r], MOD[m].first);
        return ans;
    }
    ll ans = lucas(n / MOD[m].first, r / MOD[m].first, m);
    ans = mul(ans, lucas(n % MOD[m].first, r % MOD[m].first, m), MOD[m].first);
    return ans;
}

int E(ll n, ll p)
{
    int ans = 0;
    ll a = p;
    while (n >= a)
    {
        ans += (n / a);
        a *= p;
    }
    return ans;
}

ll f(ll n, int m)
{
    ll p = pow(MOD[m].first, MOD[m].second);
    int e = n / p;
    return mul(fastPow(FMOD[m][p - 1], e, p), FMOD[m][n % p], p);
}

ll F(ll n, int m)
{
    ll p = pow(MOD[m].first, MOD[m].second);
    ll temp = 1;
    ll ans = 1;
    while (temp <= n)
    {
        ans = mul(ans, f(n / temp, m), p);
        temp *= MOD[m].first;
    }
    return ans;
}

ll granville(ll n, ll r, int m)
{
    int e = E(n, MOD[m].first) - E(n - r, MOD[m].first) - E(r, MOD[m].first);
    ll p = pow(MOD[m].first, MOD[m].second);
    if (e >= MOD[m].second)
        return 0;
    ll ans = fastPow(MOD[m].first, e, p);
    ans = mul(ans, F(n, m), p);
    ans = mul(ans, fastPow(F(r, m), pow(MOD[m].first, MOD[m].second - 1) * (MOD[m].first - 1) - 1, p), p);
    ans = mul(ans, fastPow(F(n - r, m), pow(MOD[m].first, MOD[m].second - 1) * (MOD[m].first - 1) - 1, p), p);
    return ans;
}
ll nCr(ll n, ll r)
{
    if (n == r or r == 0)
        return 1;
    if (r == 1 or r == n - 1)
        return n % 142857;
    //Calculate nCr Mod 27,11,13,37 and recombine.2
    ll ans;
    ll mod = 1;
    //Set first value
    if (MOD[0].second == 1)
        ans = lucas(n, r, 0);
    else
    {
        ans = granville(n, r, 0);
    }
    mod *= (pow(MOD[0].first, MOD[0].second));
    //Combine all
    repx(m, 1, MOD.size())
    {
        if (MOD[m].second == 1)
            ans = CRT(ans, mod, lucas(n, r, m), MOD[m].first).first;
        else
        {
            ans = CRT(ans, mod, granville(n, r, m), pow(MOD[m].first,MOD[m].second).first;
        }
        mod *= (pow(MOD[m].first, MOD[m].second));
    }
    return ans;
}

void preCompute()
{
    rep(i, MOD.size())
    {
        if (MOD[i].second > 1)
        {
            FMOD[i].assign(pow(MOD[i].first, MOD[i].second), 1);
            repx(j, 2, FMOD[i].size())
            {
                if (j % MOD[i].first == 0)
                {
                    FMOD[i][j] = FMOD[i][j - 1];
                }
                else
                {
                    FMOD[i][j] = mul(FMOD[i][j - 1], j, FMOD[i].size());
                }
            }
        }
        else
        {
            FMOD[i].assign(MOD[i].first, 1);
            invFMOD[i].assign(MOD[i].first, 1);

            repx(j, 2, MOD[i].first)
            {
                FMOD[i][j] = mul(FMOD[i][j - 1], j, MOD[i].first);
                ll temp;
                gcdext(FMOD[i][j], MOD[i].first, invFMOD[i][j], temp);
                invFMOD[i][j] = add(invFMOD[i][j], MOD[i].first, MOD[i].first);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preCompute();
    int t;
    cin >> t;
    rep(_, t)
    {
        ll n, r;
        cin >> n >> r;
        cout << nCr(n, r) << '\n';
    }
}