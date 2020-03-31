#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
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

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

int n, p, k;
graph s;
wgraph dp;

par func(int i, int bitmask)
{
    //debugx(make_pair(i, bitmask));
    if (i >= n)
        return ((bitmask + 1) >> p) ? make_pair(0, 0) : make_pair((int)-1e9, -1);

    if (dp[i][bitmask].first != -1)
        return dp[i][bitmask];
    par temp;
    par ans = func(i + 1, bitmask);
    rep(j, p)
    {
        if (bitmask & (1 << j))
            continue;
        temp = func(i + 1, bitmask + (1 << j));
        temp.first += s[i][j + 1];
        ans = max(ans, temp);
    }
    if (i >= n - (p + k))
    {
        temp = func(i + 1, bitmask);
        temp.first += s[i][0];
        temp.second += 1;
        if (temp.second <= k)
            ans = max(ans, temp);
    }

    return dp[i][bitmask] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> k;
    s.assign(n, vi(p + 1));
    rep(i, n) cin >> s[i][0];
    rep(i, n) rep(j, p) cin >> s[i][j + 1];
    sort(s.begin(), s.end());
    //debugm(s);
    dp.assign(n, vp(1 << p, {-1, -1}));
    cout << func(0, 0).first << '\n';
    //debugm(dp);
}