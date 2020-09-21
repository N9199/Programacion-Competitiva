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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
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

template <class node>
class SegTreeLazy
{
    vector<node> st;
    int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j)
        {
            st[u] = arr[i];
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr);
        build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x)
    {
        // nota, las operaciones pueden ser un and, or, ..., etc.
        if (i != j)
        {
            st[u * 2 + 1] = node(i, (i + j) / 2, x);
            st[u * 2 + 2] = node((i + j) / 2 + 1, j, x);
            st[u] = node(st[u * 2 + 1], st[u * 2 + 2]);
        }
        else
        {
            st[u] = node(x);
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
            return st[u];
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
    SegTreeLazy(vector<node> &v)
    {
        n = v.size();
        st.resize(n * 4 + 5);
        build(0, 0, n - 1, v);
    }

    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, ll value) { update(a, b, value, 0, 0, n - 1); }
};

int main()
{
    unordered_map<int, char> m;
    m[-1] = '-';
    m[0] = '0';
    m[1] = '+';
    int n, k;
    while (cin >> n >> k)
    {
        vector<prodsgn> v(n);
        rep(i, n)
        {
            int temp;
            cin >> temp;
            v[i] = prodsgn(temp);
        }
        SegTreeLazy<prodsgn> ST(v);
        char c;
        rep(_, k)
        {
            cin >> c;
            if (c == 'C')
            {
                int i, x;
                cin >> i >> x;
                ST.update(i - 1, i - 1, x);
            }
            else
            {
                int i, j;
                cin >> i >> j;
                cout << m[ST.query(i - 1, j - 1).value];
            }
        }
        cout << '\n';
    }
}