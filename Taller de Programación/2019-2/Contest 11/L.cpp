#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
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

int n, k;
vi photos;
graph dp;
int func(int i, int j) // i: where I am now, j: where I was when I started this block
{
    assert(i >= -1 and j>=i);
    assert(j < n);
    debugx(make_pair(i, j));
    if (j < k)
        return 1e9;
    if(i==0 and j==k-1)
        return photos[k-1] - photos[0];
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 1e9;
    if (i >= k)
    {
        ans = max(func(i - k, i-1), photos[j] - photos[i]);
    }
    debugx(ans);
    invrep(a, 0, i)
    {
        ans = min(ans, func(a, j));
    }
    debugx(make_pair(i, j));
    debugx(ans);
    return dp[i][j] = ans;
}

int main()
{
    cin >> n >> k;
    photos.resize(n);
    dp.assign(n, vi(n, -1));
    rep(i, n)
    {
        cin >> photos[i];
    }
    sort(photos.begin(), photos.end());
    debugx("Sanity Check");
    cout << func(n - 1, n - 1) << '\n';
    debugm(dp);
}