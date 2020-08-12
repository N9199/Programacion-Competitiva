#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

// Reps are inclusive exclusive (i.e. range is [a,b))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

// Base two log for ints and for ll
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m) //          \
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
const double PI = 3.141592653589793238462643383279502884L;

int n, m;
vi p;
vi q;
inline double dist(int i, int j)
{
    double a = 2. * PI / double(m);
    if (i > j)
        swap(i, j);
    a = a * double(min(j - i, m + i - j));

    return abs(2. * sin(a * 0.5));
}
vector<vector<double>> dp;
double func(int i, int j)
{
    assert(p[i] == q[j]);
    if (i == n - 1)
        return 0;
    if (dp[i][j] > -0.5)
        return dp[i][j];
    double ans = 1e9;
    rep(k, m) if (q[k] == p[i + 1]) ans = min(ans, dist(j, k) + func(i + 1, k));
    return dp[i][j] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp.assign(101, vector<double>(101, -1.));

    cout.setf(ios::fixed);
    cout.precision(6);
    cin >> n;
    p.resize(n);
    rep(i, n) cin >> p[i];
    cin >> m;
    q.resize(m);
    rep(i, m) cin >> q[i];
    double ans = 1e9;
    rep(i, m) if (q[i] == p[0]) ans = min(ans, func(0, i));
    cout << 1.0 + ans << '\n';
}