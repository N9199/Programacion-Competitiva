#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> par;
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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

class UnionFind
{
private:
    int numSets;
    vi p, rank, setSize;

public:
    UnionFind(int n)
    {
        numSets = n;
        rank.assign(n, 0);
        setSize.assign(n, 1);
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    void reset(int n)
    {
        numSets = n;
        rank.assign(n, 0);
        setSize.assign(n, 1);
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
    void UnionSet(int i, int j)
    {
        if (not isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int setOfSize(int i)
    {
        return setSize[i];
    }
};

ll inline dist(par &a, par &b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

const long double e = 0.00001;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.setf(ios::fixed);
    std::cout.precision(3);

    int n, w, h;
    UnionFind u(0);
    vector<vector<ll>> dists;
    vector<ll> leftwall;
    vector<ll> rightwall;

    while (cin >> n >> w >> h)
    {
        if (n == -1)
            return 0;

        dists.assign(n, vector<ll>(n, -1));
        leftwall.assign(n, -1);
        rightwall.assign(n, -1);
        vp nodes(n);
        rep(i, n)
        {
            cin >> nodes[i].first >> nodes[i].second;
            leftwall[i] = min(nodes[i].first, h - nodes[i].second);
            rightwall[i] = min(nodes[i].second, w - nodes[i].first);
            repx(j, 0, i)
            {
                dists[i][j] = dists[j][i] = dist(nodes[i], nodes[j]);
            }
        }
        long double l = 0;
        long double r = max(h, w);
        long double _4R;
        long double mid;
        int loops = 50;
        // Node LeftUp Wall
        // Node RightDown Wall
        while (l < r and (loops--))
        {
            u.reset(n + 2);
            mid = (l + r) * 0.5;
            _4R = 4 * mid * mid;
            bool touch = false;
            rep(i, n)
            {
                if (leftwall[i] >= mid)
                    continue;
                if (rightwall[i] < mid)
                {
                    touch = true;
                    goto last;
                }
                u.UnionSet(i, n);
            }
            rep(i, n)
            {
                if (rightwall[i] >= mid)
                    continue;
                u.UnionSet(i, n + 1);
            }
            rep(i, n - 1)
            {
                repx(j, i + 1, n)
                {
                    if (dists[i][j] < _4R)
                    {
                        u.UnionSet(i, j);
                        if (u.isSameSet(n, n + 1))
                        {
                            touch = true;
                            goto last;
                        }
                    }
                }
            }
        last:
            if (touch)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        std::cout << (l + r + 0.001) * 0.5 << '\n';
    }
    return 0;
}