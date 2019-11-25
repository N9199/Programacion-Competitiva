#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; ++i)
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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << _p.first << ' ' << _p.second;
    return _os;
}

struct FenwickTree
{
    vector<ll> FT;
    FenwickTree(int N)
    {
        FT.assign(N + 1, 0);
    }

    ll query(int i)
    {
        ll ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    ll query(int i, int j)
    {
        return query(j) - query(i - 1);
    }

    void update(int i, ll v)
    {
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v;
    }

    //Queries puntuales, Updates por rango
    void update(int i, int j, ll v)
    {
        update(i, v);
        update(j + 1, -v);
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    FenwickTree ft(n);
    ft.update(1, n, c);
    int u, v;
    ll k;
    int p;
    char t;
    rep(_, m)
    {
        cin >> t;
        if (t == 'Q')
        {
            cin >> p;
            cout << ft.query(p) << '\n';
        }
        else
        {
            //assert(t == 'S');
            cin >> u >> v >> k;
            ft.update(u, v, k);
        }
    }
    return 0;
}
