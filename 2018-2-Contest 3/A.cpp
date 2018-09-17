#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugp(p) cerr << #p << ": (" << p.first << ", " << p.second << ")" << endl
#define debugv(v) \
    //cerr << #v << ":";                          \
    rep(i, (int)v.size()) cerr << ", " << v[i]; \
    cerr << endl
#define debugm(m) \
    //cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) \
    //cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int d;

class UnionFind
{
  private:
    int n;
    vi rank, p;

  public:
    UnionFind(int n) : n(n)
    {
        rank.assign(n, 1);
        p.assign(n, 0);
        rep(i, n) p[i] = i;
    }

    int findSet(int i)
    {
        return p[i] == i ? i : p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int u, int v)
    {
        if (!isSameSet(u, v))
        {
            u = findSet(u);
            v = findSet(v);
            if (rank[u] > rank[v])
                p[v] = u;
            else
            {
                p[u] = v;
                if (rank[u] == rank[v])
                    rank[v]++;
            }
        }
    }
};

graph dp(10000, vi(200, -1));
vp comp;
int func(int c, int i, int t)
{
    if (i < 0)
        return 0;

    if (dp[c][i] != -1)
        return dp[c][i];

    if (c >= comp[i].second and comp[i].first * t > 0)
        return dp[c][i] = max(func(c, i - 1, t), t * comp[i].first + func(c - comp[i].second, i - 1, t));
    else
        return dp[c][i] = func(c, i - 1, t);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p, r, b;
    while (cin >> d >> p >> r >> b)
    {
        vi prices(d + p);
        UnionFind u(d + p);
        rep(i, d + p)
        {
            cin >> prices[i];
        }
        rep(i, r)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            b += d;
            u.unionSet(a, b);
        }
        comp.assign(d + p, par(0, 0));
        rep(i, d + p)
        {
            comp[u.findSet(i)].first += i < d ? -1 : 1;
            comp[u.findSet(i)].second += prices[i];
        }

        cout << d + func(b, comp.size() - 1, 1) << " ";
        dp.assign(10000, vi(200, -1));

        cout << p + func(b, comp.size() - 1, -1) << "\n";
        dp.assign(10000, vi(200, -1));
    }
    return 0;
}
