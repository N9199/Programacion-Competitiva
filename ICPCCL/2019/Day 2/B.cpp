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

ll MOD = (int)1e9 + 7;
ll N;

vi DP;
vector<bool> steps;
ll func(ll n)
{
    if (n >= N)
        return 1;
    if (DP[n] != -1)
        return DP[n];

    if (steps[n + 1] and steps[n + 2])
        return DP[n] = 0;

    if (steps[n + 1])
        return DP[n] = (func(n + 2) % MOD);

    if (steps[n + 2])
        return DP[n] = (func(n + 1) % MOD);

    if (n + 2 <= N)
        return DP[n] = ((func(n + 1) + func(n + 2)) % MOD);

    return DP[n] = (func(n + 1) % MOD);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> N >> m;
    DP.assign(N + 1, -1);
    steps.assign(N + 2, false);
    rep(i, m)
    {
        int t;
        cin >> t;
        steps[t] = true;
    }
    cout << func(0) << endl;
}