#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

// Reps are inclusive exclusive (i.e. range is [a,b))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

// Base two log for ints and for ll
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m)             \
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

struct frac
{
    ll num, den;
    frac(ll a, ll b) : num(a), den(b)
    {
        if (num < 0)
            num *= -1, den *= -1;
        auto g = abs(gcd(num, den));
        num /= g, den /= g;
    }
    frac() : num(0), den(1)
    {
        if (num < 0)
            num *= -1, den *= -1;
        auto g = abs(gcd(num, den));
        num /= g, den /= g;
    }
    frac operator+(const frac &o) const
    {
        return frac(num * o.den + o.num * den, den * o.den);
    }

    frac operator*(const frac &o) const
    {
        return frac(num * o.num, den * o.den);
    }
    frac operator/(const frac o) const
    {
        return frac(num * o.den, den * o.num);
    }
    bool operator<(const frac &o) const
    {
        return num * o.den < den * o.num;
    }
    bool operator==(const frac &o) const
    {
        return num == o.num && den == o.den;
    }
    friend ostream &operator<<(ostream &str, const frac &a);
};

ostream &operator<<(ostream &strm, const frac &a)
{
    strm << a.num << ' ' << a.den;
    return strm;
}

inline frac func(frac &a, frac &b)
{
    return (a * b) / (a + b);
}

map<frac, pair<frac, frac>> p;

bool bfs(frac &end)
{
    queue<pair<frac, frac>> q;
    pair<frac, frac> start = {frac(1, 1), frac(1, 1)};
    q.emplace(start);
    while (not q.empty())
    {
        auto u = q.front();
        q.pop();
        auto o = func(u.first, u.second);
        p[o] = u;
        if (o < end)
            continue;
        if (o == end)
            return true;
        q.emplace(u.first, o);
        q.emplace(o, u.second);
        q.emplace(o, o);
    }
    return false;
}

void reconstruct(frac &end)
{
    stack<pair<frac, frac>> s;
    auto curr = end;
    const auto temp = frac(1, 1);
    while (curr < temp)
    {
        s.emplace(p[curr]);
        curr = min(p[curr].first, p[curr].second);
    }

    while (!s.empty())
    {
        auto out = s.top();
        s.pop();
        cout << out.first << '\n'
             << out.second << '\n';
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    auto end = frac(n, m);
    if (bfs(end))
        reconstruct(end);
    else
        cout << "*\n";
}