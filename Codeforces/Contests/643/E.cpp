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
#define debugx(x) //cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v) //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m) //              \
    cerr << #m << ":" << endl; \
    for (auto v : m)           \
    {                          \
        for (auto e : v)       \
            cerr << " " << e;  \
        cerr << endl;          \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
int n, a, r, m;
vi H;

int cost(int h)
{
    int above = 0;
    int below = 0;
    rep(i, n)
    {
        above += max(0, H[i] - h);
        below += max(0, h - H[i]);
    }
    if (m > (a + r))
        return above * r + below * a;
    else
        return min(above, below) * m + max(0, above - below) * r + max(0, below - above) * a;
}

int min_search(int l, int r)
{ // convex cost function
    while (l < r)
    {
        int m = (l + r) >> 1;
        int slope = cost(m + 1) - cost(m);
        if (slope >= 0)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> r >> m;
    H.assign(n, 0);
    rep(i, n) cin >> H[i];
    sort(H.begin(), H.end());
    int ans = cost(H[0]);
    rep(i, n - 1) ans = min(ans, min_search(H[i], H[i + 1]));
    cout << ans << '\n';
}