#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vii> wgraph;
typedef vector<vi> graph;
typedef vector<vll> vvll;

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

int main()
{
    set<ll> powers;
    ll n = 1;
    while (n < 1e18)
    {
        powers.emplace(n);
        n *= 3;
    }
    powers.emplace(n);
    int q;
    cin >> q;
    rep(i, q)
    {
        ll m,ans=0,ans2=0;
        cin >> m;
        if(powers.find(m) != powers.end()){
            cout << m << '\n';
            continue;
        }
        while (m > 0)
        {
            debugx(m);
            auto it = powers.lower_bound(m);
            debugx(*it);
            ans += *it;
            m -= *(++it);
        }

        if (m < 0)
            cout << ans << '\n';
        else
            cout << m << '\n';
    }
}