#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

ll inline mod(ll x, ll m)
{
    return ((x %= m) < 0) ? x + m : x;
}
ll inline mul(ll x, ll y, ll m) { return (x * y) % m; }
ll inline add(ll x, ll y, ll m) { return (x + y) % m; }

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
        g = -g, x = -x, y = -y;
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
pair<ll, ll> CRT(ll r1, ll m1, ll r2, ll m2)
{
    ll g, x, y;
    g = gcdext(m1, m2, x, y);
    if ((r1 - r2) % g != 0)
        return {-1, -1}; // no solution
    ll z = m2 / g;
    ll lcm = m1 * z;
    ll sol = add(mod(r1, lcm), m1 * mul(mod(x, z), mod((r2 - r1) / g, z), z), lcm);
    return {sol, lcm}; // solution + lcm(m1,m2)
}

ll modularInverse(ll n, ll mod)
{
    ll x, y;
    ll g = gcdext(n, mod, x, y);
    return ((x % mod + mod) % mod);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, k;
    vi infected;
    graph jumps;
    graph accum_jumps;
    vi A;
    vi pos;
    while (cin >> n >> r >> k)
    {
        infected.assign(r, 0);
        jumps.assign(r, vi(k));
        accum_jumps.assign(r, vi(k));
        A.assign(r, 0);
        pos.assign(r, 0);
        rep(i, r)
        {
            cin >> pos[i];
        }
        rep(i, r) rep(j, k)
        {
            cin >> jumps[i][j];
            A[i] += jumps[i][j];
            accum_jumps[i][j] = jumps[i][j];
            if (k > 0)
            {
                accum_jumps[i][j] += accum_jumps[i][j - 1];
            }
        }
        priority_queue<par, vp, greater<par>> q;
        q.emplace(0, 0);
        ll maxt = 0;
        debugx("Hola");
        debugm(jumps);
        debugm(accum_jumps);
        debugv(infected);
        while (not q.empty())
        {
            int c = q.top().second;
            ll t = q.top().first;

            q.pop();
            if (infected[c])
                continue;

            maxt = max(t, maxt);
            infected[c] = 1;

            rep(i, r)
            {
                if (i == c)
                    continue;
                vi times(k);
                ll g = __gcd(n, A[i] - A[c]);

                ll accum = pos[i] - pos[c];

                accum += accum_jumps[i][t % k];
                accum -= accum_jumps[c][t % k];
                accum %= g;

                // Check if they're in the same position right now
                if (pos[i] - pos[c] + accum_jumps[i][(t) % k] - accum_jumps[c][(t) % k] + A[i] * (t / k) - A[c] == 0)
                {
                    continue;
                }
                repx(j, 1, k)
                {
                    if (accum == 0)
                    {
                        ll temp = pos[i] - pos[c] + accum_jumps[i][(j + t) % k] - accum_jumps[c][(j + t) % k];
                        // Solve temp + At = 0 mod N
                        // Solve temp/g + A/g*t = 0 mod N/g
                        ll pt = n / g - (temp * modularInverse((A[i] - A[c]) / g, n / g)) % (n / g);
                        pt *= g;
                        debugx(pt + t);
                        q.emplace(pt + t, i);
                    }
                    accum += jumps[i][(j + t) % k] - jumps[c][(j + t) % k];
                    accum %= g;
                }
            }
        }
        int count = 0;
        for (auto f : infected)
            count += f;

        std::cout << count << " " << maxt << '\n';
    }
}