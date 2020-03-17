#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

#define debugx(x) //cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
int n, m;
vector<vector<ll>> A;
vector<vector<ll>> H;
vector<vector<ll>> V;

vector<vector<vector<ll>>> dp;

ll func(int f, int l, int r)
{
    if (l == r and r == m and f == n)
        return 0;
    if (dp[f][l][r] > -1e18)
        return dp[f][l][r];
    ll ans = LLONG_MIN;
    if (l < r)
        ans = max(ans, func(f, l + 1, r) - H[f][l]);
    if (r < m)
        ans = max(ans, func(f, l, r + 1) - H[f][r]);
    if (f < n)
        ans = max(ans, func(f + 1, l, r) - V[f][l] - V[f][r] + (A[f][r] - A[f][l]));
    return dp[f][l][r] = ans;
}

int main()
{
    cin >> n >> m;
    dp.assign(n + 1, vector<vector<ll>>(m + 1, vector<ll>(m + 1, -1e18)));
    A.assign(n, vector<ll>(m + 1, 0));
    H.assign(n + 1, vi(m, 0));
    V.assign(n, vi(m + 1, 0));
    rep(i, n) rep(j, m)
    {
        cin >> A[i][j + 1];
        A[i][j + 1] = A[i][j + 1] + A[i][j];
    }
    rep(i, n + 1) rep(j, m)
    {
        cin >> H[i][j];
    }
    rep(j, m + 1) rep(i, n)
    {
        cin >> V[i][j];
    }
    cout << func(0, 0, 0) << '\n';
}