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

// Numeración en [0,n-1] y [0,m-1]
template <class T>
class FenwickTree2D
{
    vector<vector<T>> t;
    int n, m;

public:
    FenwickTree2D() {}

    FenwickTree2D(int n, int m)
    {
        t.assign(n, vector<T>(m, 0));
        this->n = n;
        this->m = m;
    }

    void reset(int n, int m)
    {
        rep(i, n) rep(j, m) t[i][j] = 0;
    }

    void add(int r, int c, T value)
    {
        for (int i = r; i < n; i |= i + 1)
            for (int j = c; j < m; j |= j + 1)
                t[i][j] += value;
    }

    // sum[(0, 0), (r, c)]
    T sum(int r, int c)
    {
        T res = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
                res += t[i][j];
        return res;
    }

    // sum[(r1, c1), (r2, c2)]
    T sum(int r1, int c1, int r2, int c2)
    {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) +
               sum(r1 - 1, c1 - 1);
    }

    T get(int r, int c) { return sum(r, c, r, c); }

    void set(int r, int c, T value) { add(r, c, -get(r, c) + value); }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    FenwickTree2D<ll> FT(1025, 1025);
    int n;
    string s;
    int x1, y1, x2, y2, val;
    rep(_, t)
    {
        cin >> n;
        FT.reset(n + 1, n + 1);
        while (cin >> s)
        {
            if (s == "END")
                break;
            if (s == "SET")
            {
                cin >> x1 >> y1 >> val;
                x1++, y1++;
                FT.set(x1, y1, val);
            }
            else
            {
                cin >> x1 >> y1 >> x2 >> y2;
                x1++, y1++, x2++, y2++;
                cout << FT.sum(x1, y1, x2, y2) << '\n';
            }
        }
    }
}