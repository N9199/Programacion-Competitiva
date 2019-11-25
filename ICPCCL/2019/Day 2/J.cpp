#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
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
#define debugm(m)  //\
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

umap<ll, int> DP;
int n;
vi x;
vi h;
int f(ll len, int i)
{
    if (i == n - 1)
        return 1;
    if (DP.find(len) != DP.end())
    {
        if (DP[len] != -1)
            return DP[len];
    }
    else
        DP.emplace(len, -1);

    if (i == 0)
        return DP[len] = 1 + f(x[0], 1);

    if (x[i] - h[i] > len)
        return DP[len] = 1 + f(x[i], i + 1);

    DP[len] = f(x[i], i + 1);

    if (x[i] + h[i] < x[i + 1])
        DP[len] = max(DP[len], f(x[i] + h[i], i + 1) + 1);

    return DP[len];
}

int main()
{
    cin >> n;
    x.assign(n, 0);
    h.assign(n, 0);
    rep(i, n)
    {
        cin >> x[i] >> h[i];
    }
    ll total = f(0, 0);
    cout << total << '\n';
}