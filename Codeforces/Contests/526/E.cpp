#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

// DP[i] = max(DP[j]-A[j]+Area(i,j)) j en [i+1,n-1]

// i-ésimo y hago el update al segment tree, para el cálculo de Area(i,j)
// Area(i,j)=x_j*y_j-x_i*y_j
// DP[i] = max(m[j]*x[i]+n[j]), m=-y_j, n=x_j*y_j-A[j]+DP[j]

struct Line
{
    mutable ll k, m, p;
    bool operator<(const Line &o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

// (for doubles, use inf = 1/.0, div(a,b) = a/b)
struct LineContainer : multiset<Line, less<>>
{
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y)
    {
        if (y == end())
        {
            x->p = inf;
            return false;
        }
        if (x->k == y->k)
            x->p = x->m > y->m ? inf : -inf;
        else
            x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m)
    {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z))
            z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x)
    {
        if(empty())
            return 0;
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

struct point
{
    ll x, y, a;
    point(int x, int y, int a) : x(x), y(y), a(a) {}
    point() {}
    bool operator<(const point &o) const { return x < o.x; }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<point> points(N);
    LineContainer LC;
    rep(i, N) cin >> points[i].x >> points[i].y >> points[i].a;
    sort(points.begin(), points.end());
    ll ans = 0;
    invrep(i, 0, N)
    {
        ll m = points[i].y;
        ll n = points[i].y * points[i].x - points[i].a;
        ll temp = LC.query(-points[i].x);
        ans = max(n + max(temp, 0ll), ans);
        LC.add(m, n + max(temp, 0ll));
    }
    cout << ans << '\n';
}
