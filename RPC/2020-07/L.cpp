#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
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

#define ff first
#define ss second

inline bool in(int i, int mask)
{
    return mask & (1 << i);
}
inline int set_minus(int mask1, int mask2) { return mask1 & ~mask2; }
inline int iToM(int i){return 1<<i;}
vector<string> s;
string t;
bool check(int i, int j)
{
    bool ans = j+s[i].size()<t.size();
    rep(k, s[i].size()) if(ans &= t[j + k] == s[i][k]);
    return ans;
}
vector<vector<int>> dp;
int n;
int func(int i, int mask)
{
    if (i == t.size())
        return 1;
    if(i>t.size())
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    debugx(i);
    debugx(mask);
    assert(i<dp.size());
    assert(mask<dp[0].size());
    dp[i][mask] = 0;
    repx(j, 1, n + 1) if (in(j, mask) and check(j, i))
    {
        dp[i][mask] |= func(i + s[j-1].size(), set_minus(mask, iToM(j)));
    }
    debugx("a");
    if (in(0, mask))
    {
        dp[i][mask] |= func(i + 1, set_minus(mask, iToM(0)));
        dp[i][mask] |= func(i + 2, set_minus(mask, iToM(0)));
    }
    debugx("a");
    return dp[i][mask];
}

int main()
{
    cerr << "a" << endl;
    cin >> t;debugx("a");
    cin >> n;
    dp.assign(t.size(), vi(1<<(n+1),-1));
    s.resize(n);
    rep(i, n) cin >> s[i];
    debugx(t);
    debugx(n);
    debugv(s);
    cout << func(0, 1 << (n + 1) - 1) << '\n';
}
