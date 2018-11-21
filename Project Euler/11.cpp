#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v) //\
    cerr << #v << ":";                          \
    rep(i, (int)v.size()) cerr << ", " << v[i]; \
    cerr << endl
#define debugm(m)                                        \
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

int main()
{
    int n = 20;
    graph g(n, vi(n, 0));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> g[i][j];
        }
    }

    int c_max = 0;
    rep(i, n - 4)
    {
        rep(j, n)
        {
            c_max = max(c_max, g[i][j] * g[i + 1][j] * g[i + 2][j] * g[i + 3][j]);
            c_max = max(c_max, g[j][i] * g[j][i + 1] * g[j][i + 2] * g[j][i + 3]);
        }
    }
    debugx(c_max);
    rep(i, n - 4)
    {
        rep(j, n - 4)
        {
            c_max = max(c_max, g[i][j] * g[i + 1][j + 1] * g[i + 2][j + 2] * g[i + 3][j + 3]);
            c_max = max(c_max, g[i][n - 3 - j] * g[i + 1][n - 3 - (j + 1)] * g[i + 2][n - 3 - (j + 2)] * g[i + 3][n - 3 - (j + 3)]);
        }
    }

    cout << c_max << endl;
    return 0;
}