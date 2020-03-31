#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto &v : m)         \
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

int base, p;

int mulmod(uint a, uint b, uint p)
{
    int x = 0, y = a % p;
    while (b)
    {
        if (b & 1)
            x = (x + y) % p;
        y = (y << 1) % p;
        b >>= 1;
    }
    return x % p;
}

int fastPow(int x, int n, int MOD)
{
    int ret = 1;
    while (n)
    {
        if (n & 1)
            ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret;
}

struct Jupiter
{
    int value, size;
    Jupiter() { value = 0, size = 0; }
    Jupiter(int x) { value = x, size = 1; }
    Jupiter(const Jupiter &a, const Jupiter &b) { value = (mulmod(a.value, fastPow(base, b.size, p), p) + b.value) % p, size = a.size + b.size; }
};

template <class node>
class ST
{
    vector<node> *arr, st;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j)
        {
            st[u] = (*arr)[i];
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m);
        build(r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    node query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return node();
        if (a <= i and j <= b)
            return st[u];
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        node x = query(a, b, l, i, m);
        node y = query(a, b, r, m + 1, j);
        return node(x, y);
    }

    void update(int a, ll value, int u, int i, int j)
    {
        if (j < a or a < i)
            return;
        if (i == j)
            st[a] = node(value);
        else
        {
            int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
            update(a, value, l, i, m);
            update(a, value, r, m + 1, j);
            st[u] = node(st[l], st[r]);
        }
    }

public:
    ST(vector<node> &v)
    {
        arr = &v;
        n = v.size();
        st.resize(n * 4 + 5);
        build(0, 0, n - 1);
    }

    node query(int a, int b)
    {
        return query(a, b, 0, 0, n - 1);
    }
    // 1-Indexed?
    void update(int a, ll value)
    {
        update(a, value, 0, 0, n - 1);
    }

    void debug()
    {
        cerr << "Array: ";
        rep(i, n)
        {
            node temp = query(i, i + 1);
            cerr << make_pair(temp.value, temp.size) << ' ';
        }
        cerr << endl;
        rep(i, n - 1)
        {
            node temp = query(i, i + 2);
            cerr << make_pair(temp.value, temp.size) << ' ';
        }
        cerr << endl;
        cerr << "ST: ";
        rep(i, 4 * n+5)
        {
            node temp = (*arr)[i];
            cerr << make_pair(temp.value, temp.size) << ' ';
        }
        cerr << endl;
    }
};

int main()
{
    int l, n;
    while (cin >> base >> p >> l >> n)
    {
        if (base == 0)
            return 0;
        vector<Jupiter> v(l);
        ST<Jupiter> t(v);
        char c;
        int j, a;
        rep(i, n)
        {
            cin >> c >> j >> a;
            if (c == 'E')
                t.update(j, a);
            else
            {
                debugx(make_pair(j, a));
                cout << t.query(j - 1, a).value << '\n';
            }
            t.debug();
        }
        cout << "-\n";

        t.debug();
    }
    return 0;
}