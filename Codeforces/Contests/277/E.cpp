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

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m)  //           \
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

vector<int> L;
graph length;
vector<int> vals;

//Bottom up approach O(nlogn)
int lis(int n)
{
    int maxl = 1;
    L[0] = vals[0];
    length[0][0] = maxl;
    repx(k, 1, n)
    {
        auto it = lower_bound(L.begin(), L.begin() + maxl, vals[k]);
        if (it == L.begin() + maxl)
        {
            L[maxl] = vals[k];
            maxl++;
        }
        else
            *it = vals[k];
        length[0][k] = it - L.begin() + 1;
        debugx(length[0][k]);
    }
    debugv(length[0]);
    return maxl;
}

struct comp
{
    bool operator()(const int i, const int j) const { return i > j; }
};

int lis2(int n)
{
    int maxl = 1;
    L[0] = *vals.rbegin();
    length[1][n - 1] = maxl;
    invrep(k, 0, n - 1)
    {
        auto it = lower_bound(L.begin(), L.begin() + maxl, vals[k], comp());
        if (it == L.begin() + maxl)
            L[maxl++] = vals[k];
        else
            *it = vals[k];

        length[1][k] = it - L.begin() + 1;
        debugx(length[1][k]);
    }
    debugv(length[1]);
    return maxl;
}

int main()
{
    int n;
    cin >> n;
    vals.resize(n);
    L.resize(n);
    length.assign(2, vi(n));
    rep(i, n) cin >> vals[i];
    debugv(vals);
    vi ans(n, 0);
    int maxl = lis(n);
    debugv(L);
    L.assign(n, 0);
    lis2(n);
    vi a(n);
    rep(i, n)
    {
        if (length[0][i] + length[1][i] - 1 != maxl)
        {
            ans[i] = 1;
            continue;
        }
        a[length[0][i]]++;
    }
    rep(i, n)
    {
        if (ans[i] == 1)
            continue;
        else if (a[length[0][i]] > 1)
            ans[i] = 2;
        else
            ans[i] = 3;
    }
    rep(i, n) cout << ans[i];
    cout << '\n';
}