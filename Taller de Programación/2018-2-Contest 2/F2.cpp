#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vi> graph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v) \
    //cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
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

struct din
{
    int x, y;
    din(int x, int y) : x(x), y(y) {}
    int dist(din &o) const
    {
        return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
    }
};

bool dfs(graph &g)
{
    stack<int> s;
    int n = g.size() - 2;
    s.emplace(n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    int n, w, h;
    while (cin >> n >> w >> h)
    {
        if (n == -1)
            return 0;

        vector<din> Dins;
        vi dist1;
        vi dist2;

        graph s(n + 2);

        rep(i, n)
        {
            int x, y;
            cin >> x >> y;
            Dins.eb(x, y);
            dist1.eb(min(x, h - y));
            dist2.eb(min(y, h - x));
        }

        double minR = 0;
        double maxR = max(w, h);
        double _4r2;
        graph dist_sqr_din(n, vi(n));
        rep(i, n) repx(j, i + 1, n)
        {
            dist_sqr_din[i][j] = dist_sqr_din[j][i] = Dins[i].dist(Dins[j]);
        }

        rep(_, 40)
        {
            for (auto e : s)
            {
                e.clear();
            }
            double r = (minR + maxR) * 0.5;
            _4r2 = 4 * r * r;
            
        }
    }

    return 0;
}