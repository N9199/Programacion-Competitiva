#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<int> vi;
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
#define debugv(v)         \
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

/* template <class... T>
std::ostream &operator<<(std::ostream &_os, const std::tuple<T...> &_tup)
{
    auto I = make_index_sequence<sizeof...(T)>();
    _os << '(';
    (..., (_os << (I == 0 ? "" : ", ") << std::get<I>(_tup)));
    _os << ')';
    return _os;
} */

/* template <class TupType, size_t... I>
std::ostream &tuple_print(std::ostream &os,
                          const TupType &_tup, std::index_sequence<I...>)
{
    os << "(";
    (..., (os << (I == 0 ? "" : ", ") << std::get<I>(_tup)));
    os << ")";
    return os;
}

template <class... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &_tup)
{
    return tuple_print(os, _tup, std::make_index_sequence<sizeof...(T)>());
} */

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

    void reset()
    {
        for (auto &v : t)
            fill(v.begin(), v.end(), 0);
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

graph R;
graph C;
graph V;

struct point
{
    int x, y, w;
    point(int x, int y, int w) : x(x), y(y), w(w) {}
    bool operator<(const point &o) const { return w > o.w; }
    bool operator==(const point &o) const { return x == o.x and y == o.y; }
};

void add(priority_queue<point> &q, FenwickTree2D<int> &FT, int r1, int c1, int r2, int c2, int cost)
{
    int temp = FT.sum(r1 + 1, c1 + 1, r2 + 1, c2 + 1);
    if (temp == (r2 - r1 + 1) * (c2 - c1 + 1))
        return;
    if (temp == 0)
    {
        repx(x, r1, r2 + 1) repx(y, c1, c2 + 1)
        {
            q.emplace(x, y, cost + V[x][y]);
            FT.set(x + 1, y + 1, 1);
        }
    }
    else
    {
        if (r2 - r1 > c2 - c1)
        {
            add(q, FT, r1, c1, (r1 + r2) / 2, c2, cost);
            add(q, FT, (r1 + r2) / 2 + 1, c1, r2, c2, cost);
        }
        else
        {
            add(q, FT, r1, c1, r2, (c1 + c2) / 2, cost);
            add(q, FT, r1, (c1 + c2) / 2 + 1, r2, c2, cost);
        }
    }
}

ll dijsktra(FenwickTree2D<int> &FT, point &start, point &end, int r, int c)
{
    FT.set(start.x + 1, start.y + 1, 1);
    priority_queue<point> q;
    q.emplace(start);
    while (!q.empty())
    {
        point u = q.top();
        q.pop();
        if (u == end)
            return u.w - V[u.x][u.y];
        add(q, FT,
            max(0, u.x - R[u.x][u.y]), max(0, u.y - C[u.x][u.y]),
            min(r - 1, u.x + R[u.x][u.y]), min(c - 1, u.y + C[u.x][u.y]),
            u.w);
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c, n;
    c = r = 501;
    V.assign(r, vi(c));
    R.assign(r, vi(c));
    C.assign(r, vi(c));
    FenwickTree2D<int> FT(r + 1, c + 1);
    while (cin >> r >> c >> n)
    {
        rep(x, r) rep(y, c) cin >> V[x][y];
        rep(x, r) rep(y, c) cin >> R[x][y];
        rep(x, r) rep(y, c) cin >> C[x][y];
        point curr(0, 0, 0);
        point next(0, 0, 0);
        cin >> curr.x >> curr.y;
        curr.x--, curr.y--;
        curr.w = V[curr.x][curr.y];
        rep(i, n - 1)
        {
            if (i > 0)
                cout << ' ';
            cin >> next.x >> next.y;
            next.x--, next.y--;
            next.w = V[next.x][next.y];
            cout << dijsktra(FT, curr, next, r, c);
            curr = next;
            FT.reset();
        }
        cout << '\n';
    }
}