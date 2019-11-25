#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
typedef vector<int> vi;
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

// Range Minimum Query
struct rmaxq
{
    int value;
    rmaxq() { value = 0; }
    rmaxq(int x) { value = x; }
    rmaxq(const rmaxq &a,
          const rmaxq &b)
    {
        value = max(a.value,
                    b.value);
    }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST() {}
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }

    // 0-indexed
    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = node(t[p], t[p ^ 1]);
    }

    // inclusive exclusive, 0-indexed
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansl = node(ansl, t[l++]);
            if (r & 1)
                ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

ST<rmaxq> dp;
vi op;
int n, m;
int func(int i)
{
    rmaxq ans;
    if (i >= m)
    {
        ans = dp.query(i + m, n);
        ans.value += op[i];
    }
    else
    {
        ans = dp.query(m, n);
        ans.value += op[m];
    }
    dp.set_point(i, ans);
    return ans.value;
}

int main()
{
    cin >> n >> m;
    op.assign(n, 0);
    rep(i, n)
    {
        cin >> op[i];
    }
    vector<rmaxq> temp(n, -1);
    temp[n - 1].value = op[n - 1];
    dp = ST<rmaxq>(temp);
    invrep(i, m, n)
    {
        func(i);
    }
    cout << dp.query(m, n).value << '\n';
}