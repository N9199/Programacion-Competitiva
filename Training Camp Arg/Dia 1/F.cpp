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

ll m = 1e9 + 7;
struct num
{
    ll n;
    num() : n(0) {}
    num(ll n)
    {
        this->n = (n % m + m) % m;
    }
    num operator+(const num &o) const
    {
        return (n + o.n) % m;
    }
    num operator+=(const num &o)
    {
        this->n += o.n;
        return this->n %= m;
    }
    num operator+=(const ll &o)
    {
        this->n += o;
        return this->n %= m;
    }
    num operator*(const num &o) const
    {
        return ((n * o.n) % m + m) % m;
    }
};

ostream &operator<<(ostream &os, const num &o)
{
    os << o.n;
    return os;
}

vector<vector<num>> multiply(vector<vector<num>> &a, vector<vector<num>> &o)
{
    vector<vector<num>> ans(a.size(), vector<num>(a.size()));
    int n = a.size();
    rep(i, n) rep(j, n) rep(k, n)
    {
        ans[i][j] += a[i][k] * o[k][j];
    }
    return ans;
}

vector<vector<num>> exponent(vector<vector<num>> &T, int exp)
{
    vector<vector<num>> ret(T.size(), vector<num>(T.size()));
    rep(i, T.size()) ret[i][i].n = 1;
    while (exp)
    {
        if (exp & 1)
            ret = multiply(ret, T);
        T = multiply(T, T);
        exp >>= 1;
    }
    return ret;
}

vector<num> mult(const vector<vector<num>> &T, const vector<num> &v)
{
    vector<num> ans(T.size());
    rep(i, T.size()) rep(j, v.size()) ans[i] += v[j] * T[i][j];
    return ans;
}

int main()
{
    int n, b, k, x;
    cin >> n >> b >> k >> x;
    vector<num> V0(x, 0);
    rep(i, n)
    {
        int temp;
        cin >> temp;
        temp %= x;
        V0[temp] += 1;
    }
    vector<vector<num>> A(x, vector<num>(x, 0));
    vector<vector<int>> m(x, vector<int>(x, 0));
    rep(i, x) rep(j, x)
    {
        m[i][j] = ((i - 10 * j) % x + x) % x;
    }
    //debugv(V0);
    //debugm(m);
    rep(i, x) rep(j, x) if (m[i][j] < 10)
        A[i][j] = V0[m[i][j]];
    //debugm(A);
    vector<vector<num>> ans = exponent(A, b - 1);
    vector<num> rans = mult(ans, V0);
    cout << rans[k] << '\n';
}
