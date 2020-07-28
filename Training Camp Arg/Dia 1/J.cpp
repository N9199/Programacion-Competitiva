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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, d;
    cin >> n >> d;
    int a, b;
    cin >> a >> b;
    vii w(n);
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        w[i].first = a * x + b * y;
        w[i].second = i + 1;
    }
    sort(w.begin(), w.end());
    ll accum = 0;
    int m = 0;
    bool temp = true;
    rep(i, n)
    {
        accum += (ll)w[i].first;
        m = i;
        if (accum > d)
        {
            temp = false;
            break;
        }
    }
    if(temp)
        m = n;
    cout << m << '\n';
    vi index(m);
    rep(i, m)
        index[i] = w[i].second;

    sort(index.begin(), index.end());
    rep(i, m)
    {
        if (i > 0)
            cout << ' ';
        cout << index[i];
    }
    cout << '\n';
}