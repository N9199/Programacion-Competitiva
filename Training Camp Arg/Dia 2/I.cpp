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
#define invrep(i, a, b) for (int i = b; i-- >= (int)a;)

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

template <class TupType, size_t... I>
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
}

struct FenwickTree
{
    vector<int> FT;
    FenwickTree(int N) { FT.resize(N + 1, 0); }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j) { return query(j) - query(i - 1); }

    void update(int i, int v)
    {
        int s = query(i, i); // Sets range to v?
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v - s;
    }

    // Queries puntuales, Updates por rango
    void update(int i, int j, int v)
    {
        update(i, v);
        update(j + 1, -v);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) cin >> b[i];
    FenwickTree Start(n + 1);
    FenwickTree Indices(n + 1);
    Start.update(1, n + 1, 0);
    Indices.update(1, n + 1, 0);

    int t;
    rep(_, m)
    {
        cin >> t;
        debugx(t);
        if (t == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            debugx(tie(x, y, k));
            Indices.update(y, y + k, x);
            Start.update(y, y + k, y);
        }
        else
        {
            int x;
            cin >> x;
            int start = Start.query(x);
            int index = Indices.query(x);
            debugx(tie(index, start, x));
            debugx(index + start - x);
            if (start == -1)
                cout << b[x - 1] << '\n';
            else
            {
                cout << a[index - 1 + start - x] << '\n';
            }
        }
    }
}