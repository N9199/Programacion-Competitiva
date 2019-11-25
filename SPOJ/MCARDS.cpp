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

vi colors;

struct Card
{
    int c, n;
    Card(int c, int n) : c(c), n(n) {}
    bool const operator<(const Card &o) { return tie(colors[c], n) < tie(colors[o.c], o.n); }
};
ostream &operator<<(ostream &os, const Card &c)
{
    os << "(" << c.c << " " << c.n << ")";
    return os;
}

vector<Card> L;
vector<Card> vals;

//Bottom up approach O(nlogn)
int lis(int n)
{
    int maxl = 1;
    L[0] = vals[0];
    repx(i, 1, n)
    {
        auto it = lower_bound(L.begin(), L.begin() + maxl, vals[i]);
        if (it == L.begin() + maxl)
        {
            L[maxl] = vals[i];
            maxl++;
        }
        else
            *it = vals[i];
    }
    return maxl;
}

int main()
{
    int c, n;
    cin >> c >> n;
    vals.assign(c * n, {-1, -1});
    colors.assign(c, 0);
    rep(i, c) colors[i] = i;
    rep(i, c * n)
    {
        cin >> vals[i].c >> vals[i].n;
        vals[i].c--;
    }
    int ans = c * n;
    do
    {
        L.assign(c * n + 1, {-1, -1});
        ans = min(ans, c * n - lis(c * n));
    } while (next_permutation(colors.begin(), colors.end()));

    cout << ans << '\n';
}