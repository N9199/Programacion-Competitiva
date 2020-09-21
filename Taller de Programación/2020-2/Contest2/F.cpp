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
struct query
{
    int l, r, val;
    query(int l, int r, int val) : l(l), r(r), val(val) {}
    query() : l(0), r(0), val(0) {}
};

int main()
{
    ll a[(int)1e5 + 1];
    ll queries[(int)1e5 + 1];
    query q[(int)1e5];
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, n) cin >> a[i];
    invrep(i, 1, n) a[i] -= a[i - 1];
    rep(i, m) cin >> q[i].l >> q[i].r >> q[i].val;
    int x, y;
    rep(_, k)
    {
        cin >> x >> y;
        queries[x - 1]++;
        queries[y]--;
    }
    repx(i, 1, m) queries[i] += queries[i - 1];
    rep(i, m)
    {
        a[q[i].l - 1] += queries[i] * q[i].val;
        a[q[i].r] -= queries[i] * q[i].val;
    }
    repx(i, 1, n) a[i] += a[i - 1];
    rep(i, n) cout << a[i] << ' ';
    cout << '\n';
}