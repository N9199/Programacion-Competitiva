#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
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

#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugv(v)  //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //\
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

priority_queue<int> primes;
//Criba
void sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    repx(i, 2, n + 1) if (is_prime[i]) primes.emplace(i);
}

struct RSQ // Range sum query
{
    static ll const neutro = 0;
    static ll op(ll x, ll y)
    {
        return x + y;
    }
    static ll
    lazy_op(int i, int j, ll x)
    {
        return (j - i + 1) * x;
    }
};

struct RMinQ // Range minimun query
{
    static ll const neutro = 1e18;
    static ll op(ll x, ll y)
    {
        return min(x, y);
    }
    static ll
    lazy_op(int i, int j, ll x)
    {
        return x;
    }
};

template <class t>
class SegTreeLazy
{
    vector<ll> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j)
        {
            st[u] = arr[i];
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m);
        build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x)
    {
        // nota, las operaciones pueden ser un and, or, ..., etc.
        // st[u] += t::lazy_op(i, j, x); // incrementar el valor (+)
        st[u] = t::lazy_op(i, j, x); // setear el valor
        if (i != j)
        {
            // incrementar el valor
            // lazy[u * 2 + 1] += x;
            // lazy[u * 2 + 2] += x;
            // setear el valor
            lazy[u * 2 + 1] = x;
            lazy[u * 2 + 2] = x;
        }
        lazy[u] = 0;
    }

    ll query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            return st[u];
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m + 1, j);
        return t::op(x, y);
    }

    void update(int a, int b, ll value,
                int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            propagate(u, i, j, value);
        else if (j < a or b < i)
            return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = t::op(st[l], st[r]);
        }
    }

public:
    SegTreeLazy(vector<ll> &v)
    {
        arr = v;
        n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        sieve(n + 2); //Criba para los updates
        build(0, 0, n - 1);
    }

    ll query(int a, int b)
    {
        return query(a, b, 0, 0, n - 1);
    }

    void update(ll k)
    {
        //Dado el k del query tomar los primos mayores a k y eliminar sus multiplos.
        while (primes.top() > k and not primes.empty())
        {
            debugx("Hello");
            repx(i, 1, n)
            {
                if (i % primes.top() == 0)
                {
                    debugx(i);
                    update(i, i, 0, 0, 0, n - 1);
                }
            }
            primes.pop();
        }
    }
};

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << _p.first << ' ' << _p.second;
    return _os;
}

struct FenwickTree
{
    vector<int> FT;
    int n;
    FenwickTree(int N) : n(N + 1)
    {
        FT.resize(N + 1, 0);
        sieve(N + 2);
        debugx(n);
    }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j)
    {
        return (j - i + 1) - (query(j) - query(i - 1));
    }

    void update(int i, int v)
    {
        debugx(i);
        int s = query(i, i);
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v - s;
    }

    //Queries puntuales, Updates por rango
    void update(int i, int j, int v)
    {
        update(i, v);
        update(j + 1, -v);
    }

    void update(ll k)
    {
        while (primes.top() > k and not primes.empty())
        {
            debugx("Hello");
            repx(i, 1, n)
            {
                if (i % primes.top() == 0)
                {
                    debugx(i);
                    update(i, 1);
                }
            }
            primes.pop();
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    int n, k;
    int n_max;
    umap<int, par> queries;
    map<par, int> out;
    auto comp = [](par &a, par &b) -> bool {
        return a.second < b.second;
    };

    priority_queue<par, vp, decltype(comp)> s(comp);

    rep(i, q)
    {
        cin >> n >> k;
        queries[i] = {n, k};
        s.emplace(n, k);
        n_max = max(n, n_max);
    }
    vector<ll> v(n_max + 2, 1);//Vector de 1
    SegTreeLazy<RSQ> st(v);//Segment Tree
    debugx(primes.size());//Checkear primos
    while (not s.empty())
    {
        //Responder queries
        auto temp = s.top();
        s.pop();
        debugx(temp);
        st.update(temp.second);
        out[temp] = st.query(2, temp.first);
    }
    rep(i, q)
    {
        cout << out[queries[i]] << '\n';
    }
}