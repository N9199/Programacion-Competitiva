#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vi> graph;

typedef vector<double> vd;
typedef vector<vd> vvd;

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
#define debugv(v) \
    // cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
    cerr << endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct par
{
    int x, y;
    par(int x, int y) : x(x), y(y) {}
    double dist_sqrt(par &o)
    {
        return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
    }
};

typedef vector<par> vp;

class UnionFind
{
  private:
    int n, numSets;
    vi p, rank, setSize;

  public:
    UnionFind(int n)
    {
        this->n = n;
        numSets = n;
        rank.assign(n, 0);
        p.assign(n, 0);
        rep(i, n) p[i] = i;
    }

    void reset()
    {
        numSets = n;
        rank.assign(n, 0);
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

    void UnionSet(int i, int j)
    {
        if (not isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
                p[y] = x;
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

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

        vp din;
        vi dist1;
        vi dist2;

        rep(i, n)
        {
            int x, y;
            cin >> x >> y;
            din.eb(x, y);
            dist1.eb(min(x, h - y));
            dist2.eb(min(y, w - x));
        }

        double minr = 0;
        double maxr = max(w, h);
        double r2;
        UnionFind s(n + 2);
        graph dist_sqr_din(n, vi(n));
        rep(i, n) repx(j, i + 1, n)
        {
            dist_sqr_din[i][j] = dist_sqr_din[j][i] = din[i].dist_sqrt(din[j]);
        }
        rep(i, 40)
        {
            s.reset();
            double r = (minr + maxr) / 2;
            r2 = 4 * r * r;
            bool connected = false;
            rep(i, n)
            {
                if (dist1[i] >= r)
                    continue;
                if (dist2[i] < r)
                {
                    connected = true;
                    goto next;
                }
                s.UnionSet(i, n);
            }

            rep(i, n)
            {
                if (dist2[i] < r)
                    s.UnionSet(i, n + 1);
                if (s.isSameSet(n, n + 1))
                {
                    connected = true;
                    goto next;
                }
            }

            rep(i, n) repx(j, i + 1, n)
            {
                if (dist_sqr_din[i][j] <= r2)
                {
                    s.UnionSet(i, j);
                    if (s.isSameSet(n, n + 1))
                    {
                        connected = true;
                        goto next;
                    }
                }
            }

        next:
            if (connected)
                maxr = r;
            else
                minr = r;
        }
        cout << (maxr + minr) * 0.5 << '\n';
    }
    return 0;
}