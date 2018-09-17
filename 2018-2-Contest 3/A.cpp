#include <bits/stdc++.h> //Include everything you'll need
using namespace std;     //Necessary evil

//Definitions
//Types
typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

//Reps
#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

//Vector append
#define pb push_back
#define eb emplace_back
#define ppb pop_back

//Math stuff
#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//Debugs
#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugp(p)  //cerr << #p << ": (" << p.first << ", " << p.second << ")" << endl
#define debugv(v)  //\
    cerr << #v << ":";                          \
    rep(i, (int)v.size()) cerr << ", " << v[i]; \
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

//Standard UnionFind, slimmed down for efficiency, for connected components
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

graph dp(10000, vi(200, -1)); //Max Size of dp
vp comp;                      //Components, format = (delta, cost)
int func(int c, int i, int t)
{
    // c: Budget/Cost
    // i: The ith component
    // t: A 1, or -1, depending on the party
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
    //Input/Output optimization
    ios::sync_with_stdio(0);
    cin.tie(0);
    // d: DSP members
    // p: PPP members
    // r: Rivalries
    // b: Budget
    int d, p, r, b;
    while (cin >> d >> p >> r >> b)
    {
        //Prices/Cost of each individual party members
        //Indexing from 0 to d-1 for DSP, and from d to d+p-1 for PPP
        vi prices(d + p);
        UnionFind u(d + p);
        rep(i, d + p)
        {
            cin >> prices[i];
        }
        //Do connected components while reading input
        rep(i, r)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            b += d;
            u.unionSet(a, b);
        }
        //Setup values for components
        comp.assign(d + p, par(0, 0));
        rep(i, d + p)
        {
            //Add stuff to the correct component
            comp[u.findSet(i)].first += i < d ? -1 : 1; // If i is part of DSP, -1 else +1 (arbitrary convention)
            comp[u.findSet(i)].second += prices[i];     // Price/Cost of ith party member
        }
        // DP gives delta, so d+delta (and p+delta) is the max amount for that party
        cout << d + func(b, comp.size() - 1, 1) << " ";
        dp.assign(10000, vi(200, -1)); //Reset DP

        cout << p + func(b, comp.size() - 1, -1) << "\n";
        dp.assign(10000, vi(200, -1)); //Reset DP
    }
    return 0;
}
