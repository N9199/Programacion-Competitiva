#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) //        \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m) //            \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

class UnionFind
{
    vi p, rank;
    vector<ll> setSize;

public:
    UnionFind(int n)
    {
        rank.assign(n, 0);
        setSize.assign(n, 0);
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
    void addSize(int i, ll w)
    {
        setSize[findSet(i)] += w;
    }
    void UnionSet(int i, int j)
    {
        if (not isSameSet(i, j))
        {
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
    ll sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};

struct sensor
{
    int x, y, r;
    sensor() : x(0), y(0), r(0) {}

    bool operator^(const sensor &o) const { return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y)) < r + o.r; }
};
const int Left = 0;
const int Right = 200;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<sensor> s(n);
    rep(i, n) cin >> s[i].x >> s[i].y >> s[i].r;
    UnionFind u(n + 2);
    int ans = 0;
    rep(i, n)
    {
        if (s[i].x < s[i].r)
            u.UnionSet(i, n);
        if (s[i].x + s[i].r > Right)
            u.UnionSet(i, n + 1);
        if (u.isSameSet(n, n + 1))
            goto end;
        rep(j, i)
        {
            if (s[i] ^ s[j])
                u.UnionSet(i, j);
            if (u.isSameSet(n, n + 1))
                goto end;
        }
        ans++;
    }
end:
    cout << ans << '\n';
}