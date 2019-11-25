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
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
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
#define debugm(m)                                        \
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
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

struct FenwickTree {
    vector<int> ft;
    FenwickTree(int n) { ft.assign(n+1, 0); }
    // prefix sum query (sum in range 1 .. b)
    int psq(int b) {
        int sum = 0;
        for (; b; b -= (b & -b)) sum += ft[b];
        return sum;
    }
    // range sum query (sum in range a .. b)
    int rsq(int a, int b) {
        return psq(b) - psq(a-1);
    }
    // increment k'th value by v (and propagate)
    void add(int k, int v) {
        for (; k < ft.size(); k += (k & -k)) ft[k] += v;
    }
    // increment range [i ... j] with v (and propagate)
    void range_add(int i, int j, int v) {
        add(i, v); add(j+1, -v);
    }
};

int main()
{
    int t;
    cin >> t;
    rep(_, t)
    {
        int n;
        cin >> n;
        umap<string, int> m;
        string s;
        rep(i, n)
        {
            cin >> s;
            m[s] = i;
        }
        FenwickTree moves(n);
        vi perm(n);
        vi invperm(n);
        rep(i, n)
        {
            cin >> s;
            invperm[i] = m[s];
            perm[m[s]] = i;
        }
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += invperm[i] - i + moves.psq(invperm[i] + 1);
      //      -moves.psq(invperm[i]);
            moves.range_add(1, invperm[i], 1);
        }
        cout << total << '\n';
    }
}