#pragma GCC optimize("Ofast")
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

const ll MOD = 1e9 + 7;

typedef vector<vector<ll>> matrix;
ll A[2][2];
ll ans[2][2];
ll temp[2][2];

void multiply(ll (&a)[2][2], ll (&o)[2][2], ll (&ans)[2][2])
{
    memset(ans, 0, sizeof(ans));
    int n = 2;
    rep(i, n) rep(j, n) rep(k, n)
    {
        ans[i][j] += (a[i][k] * o[k][j]) % MOD;
        ans[i][j] %= MOD;
    }
}

void exponent(ll (&A)[2][2], ll exp, ll (&ret)[2][2])
{
    memset(ret, 0, sizeof(ret));
    rep(i, 2) ret[i][i] = 1;
    while (exp)
    {
        if (exp & 1)
        {
            multiply(ret, A, temp);
            rep(i, 2) rep(j, 2) ret[i][j] = temp[i][j];
        }
        multiply(A, A, temp);
        rep(i, 2) rep(j, 2) A[i][j] = temp[i][j];
        exp >>= 1;
    }
}

vector<ll> mult(ll (&T)[2][2], const vector<ll> &v)
{
    vector<ll> ans(2);
    rep(i, 2) rep(j, 2)
    {
        ans[i] += (v[j] * T[i][j]) % MOD;
        ans[i] %= MOD;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%i", &t);
    rep(_, t)
    {
        ll a, n;
        scanf("%lld %lld", &a, &n);
        if (n == 0)
        {
            cout << 2 << '\n';
            continue;
        }
        if (n < 0)
            n *= -1;
        A[0][0] = ((a % MOD + MOD) % MOD);
        A[0][1] = MOD - 1;
        A[1][0] = 1;
        A[1][1] = 0;
        exponent(A, n, ans);
        vector<ll> V0 = {((a % MOD + MOD) % MOD), 2};
        vector<ll> rec = mult(ans, V0);
        printf("%lld\n", rec[1]);
    }
}
