#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

typedef vector<vi> graph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (size_t i = b; i-- > (size_t)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugp(p)  //cerr << #p << ": (" << p.x << ", " << p.y << ")" << endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct par
{
    ll x, y;
    par(ll x, ll y) : x(x), y(y) {}
};

typedef vector<par> vii;
typedef vector<vii> wgraph;

class UnionFind
{
  private:
    int numSet, N;
    vi p, rank;

  public:
    UnionFind(int n)
    {
        numSet = n;
        N = n;
        rank.assign(n, 0);
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSet--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
                p[y] = x;
            else
                p[x] = y;
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }
    int numSets()
    {
        return numSet;
    }
    void reset()
    {
        int n = N;
        numSet = n;
        rank.assign(n, 0);
        p.resize(n);
        rep(i, n) p[i] = i;
    }
};

ll dist_sq(par &a, par &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    while (true)
    {
        int n;
        ll w, h;
        cin >> n >> w >> h;
        if (n == -1)
            break;
        UnionFind u(n + 2);
        vii din;
        rep(i, n)
        {
            ll a, b;
            cin >> a >> b;
            din.eb(a, b);
        }
        double l = 0, r = max(w, h);
        rep(_, 40)
        {
            long double m = (l + r) / 2;
            long double m_sq = 4 * m * m;
            debugx(m);
            rep(i, n)
            {
                debugp(din[i]);
                if (din[i].x < m or h - din[i].y < m)
                    u.unionSet(i, n);
                if (w - din[i].x < m or din[i].y < m)
                    u.unionSet(i, n + 1);
                if (u.isSameSet(n, n + 1))
                    goto out;
            }
            rep(i, n) repx(j, i + 1, n)
            {
                if (dist_sq(din[i], din[j]) < m_sq)
                    u.unionSet(i, j);

                if (u.isSameSet(n, n + 1))
                    goto out;
            }
        out:
            if (u.isSameSet(n, n + 1))
                r = m;
            else
                l = m;
            u.reset();
            //debugx(l);
            //debugx(r);
            //debugx(m);
        }
        cout << (l + r) / 2 << '\n';
    }
    return 0;
}
