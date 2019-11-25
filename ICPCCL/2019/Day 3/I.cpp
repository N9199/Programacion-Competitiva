#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
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

#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugv(v)  //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //                                      \
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
int n;
vi DP;
graph cost;
vi sol;

int func(int bitmask)
{
    if (DP[bitmask] != -1)
        return DP[bitmask];

    int ans = (int)1e8;
    rep(i, n)
    {
        if ((1 << i) & bitmask)
        {
            ans = min(func(bitmask ^ (1 << i)) + 2 * cost[0][i + 1], ans);
            repx(j, i + 1, n)
            {
                if ((1 << j) & bitmask)
                {
                    ans = min(func(bitmask ^ (1 << i) ^ (1 << j)) + cost[0][i + 1] + cost[0][j + 1] + cost[i + 1][j + 1], ans);
                }
            }
            break;
        }
    }
    return DP[bitmask] = ans;
}
string s;
void rebuild(int bitmask)
{
    if (bitmask == 0)
    {
        s += "0";
        return;
    }
    s += "0 ";
    int ans = DP[bitmask];
    rep(i, n)
    {
        if ((1 << i) & bitmask)
        {
            if (ans == func(bitmask ^ (1 << i)) + 2 * cost[0][i + 1])
            {
                s += to_string(i + 1) + " ";
                rebuild(bitmask ^ (1 << i));
                return;
            }
            repx(j, i + 1, n)
            {
                if ((1 << j) & (bitmask ^ (1 << i)))
                {
                    if (ans == func(bitmask ^ (1 << i) ^ (1 << j)) + cost[0][i + 1] + cost[0][j + 1] + cost[i + 1][j + 1])
                    {
                        s += to_string(i + 1) + " " + to_string(j + 1) + " ";
                        rebuild(bitmask ^ (1 << i) ^ (1 << j));
                        return;
                    }
                }
            }
        }
    }
}

int inline dist(par &a, par &b) { return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    cin >> n;
    DP.assign((1 << n), -1);
    cost.assign(n + 1, vi(n + 1));
    DP[0] = 0;
    vp points;
    points.eb(x, y);
    rep(i, n)
    {
        cin >> x >> y;
        points.eb(x, y);
    }
    rep(i, n + 1) repx(j, i, n + 1)
    {
        cost[i][j] = cost[j][i] = dist(points[i], points[j]);
    }

    cout << func((1 << n) - 1) << '\n';
    rebuild((1 << n) - 1);
    cout << s << '\n';

}