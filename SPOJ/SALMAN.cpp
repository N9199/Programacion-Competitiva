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

int lg(ll n)
{
    int c = 0;
    while (n >>= 1)
        c++;
    return c;
}

struct prodsgn
{
    int value;
    int lazy_value = 0;
    bool lazy = false;
    prodsgn() { value = 1; }
    prodsgn(int x) { value = (x > 0) - (x < 0); }
    prodsgn(const prodsgn &a, const prodsgn &b) { value = a.value * b.value; }
    prodsgn(int i, int j, int x) { value = (x > 0) - (x < 0), lazy_value = value, lazy = true; }
};
struct sum_min
{
    ll value1; // sum
    ll value2; // min
    int lazy_value = 0;
    bool lazy = false;
    sum_min() { value1 = 0, value2 = 1e18; } // identity
    sum_min(ll x) { value1 = value2 = x; }
    sum_min(const sum_min &a, const sum_min &b) // op
    {
        value1 = a.value1 + b.value1;
        value2 = min(a.value2, b.value2);
    }
    sum_min(int i, int j, int x, const sum_min &b) //lazy op
    {
        value1 = (j - i + 1) * x + b.value1, value2 = x + b.value2;
    }
    sum_min(int x, const sum_min &b)
    {
        value1 = b.value1;
        value2 = b.value2;
        lazy = true;
        lazy_value = x + b.lazy_value;
    }
};

ostream &operator<<(ostream &_os, const sum_min &p)
{
    _os << '(' << p.value1 << ',' << p.value2 << ')';
    return _os;
}

template <class node>
class STL
{
    vector<node> st;
    int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j)
        {
            st[u] = node(arr[i]);
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr);
        build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x)
    {
        st[u] = node(i, j, x, st[u]);
        if (i != j)
        {
            st[u * 2 + 1] = node(x, st[u * 2 + 1]);
            st[u * 2 + 2] = node(x, st[u * 2 + 2]);
        }
    }

    node query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lazy)
            propagate(u, i, j, st[u].lazy_value);
        if (a <= i and j <= b)
        {
            return st[u];
        }
        node x = query(a, b, l, i, m);
        node y = query(a, b, r, m + 1, j);
        return node(x, y);
    }

    void update(int a, int b, ll value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lazy)
            propagate(u, i, j, st[u].lazy_value);
        if (a <= i and j <= b)
            propagate(u, i, j, value);
        else if (j < a or b < i)
            return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = node(st[l], st[r]);
        }
    }

public:
    STL(vector<node> &v)
    {
        n = v.size();
        st.resize(n * 4 + 5);
        build(0, 0, n - 1, v);
    }

    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, ll value) { update(a, b, value, 0, 0, n - 1); }
};

int T, n, q, parent, t, c, v;
ll salary;
vector<vector<pair<int, ll>>> g;
vi visited;
vector<sum_min> order;
vector<ii> ranges;

//dfs modificado de apuntes Pablo Messina.

void dfs(int u)
{
    visited[u] = 1;

    for (auto v : g[u])
    {
        if (!visited[v.first])
        {
            order.eb(v.second);
            ranges[v.first].first = t;
            t++;
            dfs(v.first);
            ranges[v.first].second = t - 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    rep(k, T)
    {
        cin >> n >> q;

        g.assign(n + 1, {});
        ranges.assign(n + 1, ii(0, 0));
        visited.assign(n + 1, 0);
        t = 0;

        rep(i, n)
        {
            cin >> parent >> salary;
            g[parent].eb(make_pair(i + 1, salary));
        }

        dfs(0);

        STL<sum_min> ST(order);

        cout << "Case " << k + 1 << ":\n";
        //ST.debug();
        rep(i, q)
        {
            cin >> c >> v;
            if (c == 1)
            {
                cout << ST.query(ranges[v].first, ranges[v].second).value1 << '\n';
            }
            if (c == 2)
            {
                salary = min(ST.query(ranges[v].first, ranges[v].second).value2, (ll)1000);
                debugx(salary);
                ST.update(ranges[v].first, ranges[v].second, salary);
            }
        }

        g.clear();
        order.clear();
        ranges.clear();
        visited.clear();
    }
}