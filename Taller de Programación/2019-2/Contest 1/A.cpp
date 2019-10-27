#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
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

int main()
{
    int n, q;
    cin >> n >> q;
    if (q == 0)
        return 0;
    vi a(n);
    deque<ll> deq;
    rep(i, n)
    {
        cin >> a[i];
        deq.eb(a[i]);
    }
    vi queries(q);
    rep(i, q)
    {
        cin >> queries[i];
    }
    int mod = n - 1;
    int t = 0;
    ll maxE = *max_element(a.begin(), a.end());

    umap<int, par> out;
    par temp;
    rep(i, 2 * n)
    {
        temp.first = deq.front();
        deq.pop_front();
        temp.second = deq.front();
        deq.pop_front();
        out[i + 1] = temp;
        if (temp.first > temp.second)
        {
            deq.eb(temp.second);
            deq.emplace_front(temp.first);
        }
        else
        {
            deq.eb(temp.first);
            deq.emplace_front(temp.second);
        }
    }
    for (auto query : queries)
    {
        if (query <= n)
        {
            cout << out[query] << '\n';
        }
        else
        {
            int offset = (query - n) % (n - 1);
            cout << out[n + offset] << '\n';
            //debugx(n + offset);
        }
    }
}