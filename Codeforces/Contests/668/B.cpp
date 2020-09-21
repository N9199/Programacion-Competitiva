#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
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

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    rep(_, t)
    {
        cin >> n;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];
        vector<ll> r(a);
        repx(i, 1, n) r[i] += r[i - 1];
        vector<ll> l(a);
        invrep(i, 0, n - 1) l[i] += l[i + 1];
        ll temp1 = 0;
        ll temp2 = 0;
        rep(i, n) temp1 = min(temp1, r[i]), temp2 = max(temp2, l[i]);
        cout << max(-temp1, temp2) << '\n';
    }
}