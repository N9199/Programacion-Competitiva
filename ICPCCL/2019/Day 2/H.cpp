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
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
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

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) //        \
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
int k1, k2;
int MOD = 1e8;
vector<vector<vector<int>>> DP;

int func(int n1, int n2, int t)
{
    if (n1 == 0 and t == 1)
        return n2 <= k2;
    if (n2 == 0 and t == 0)
        return n1 <= k1;
    if (n1 == 0 and t == 0)
        return 0;
    if (n2 == 0 and t == 1)
        return 0;

    if (DP[n1][n2][t] != -1)
        return DP[n1][n2][t];

    int sum = 0;
    if (t == 0)
    {
        repx(i, 1, k1 + 1)
        {
            if (n1 - i < 0)
                break;
            debugx(n1 - i);
            sum += func(n1 - i, n2, 1);
            sum %= MOD;
        }
    }
    else
    {
        repx(i, 1, k2 + 1)
        {
            if (n2 - i < 0)
                break;
            sum += func(n1, n2 - i, 0);
            sum %= MOD;
            debugx(n2 - i);
        }
    }

    return DP[n1][n2][t] = sum;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    DP.assign(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(2, -1)));

    cout << ((func(n1, n2, 0) + func(n1, n2, 1)) % MOD) << '\n';
}