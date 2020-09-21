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

enum Type
{
    Start,
    End
};

struct E
{
    Type t;
    ll x, y;
    E(Type t, ll x, ll y) : t(t), x(x), y(y) {}

    bool operator<(const E &o) const
    {
        if (o.x < x)
            return true;
        else if (o.t > t)
            return true;
        else if (t == Start)
            return o.y > y;
        else
            return o.y < y;
    }
};

ll L[(int)1e6];
ll H[(int)1e6];
//ll W[(int)1e6];

const ll MOD = 1e9 + 7;
int main()
{
    // Parse input
    int T;
    cin >> T;
    priority_queue<E> q;
    rep(C, T)
    {
        ll ans = 1;
        int n, k;
        cin >> n >> k;
        int W;
        cin >> W;
        ll a, b, c, d;
        rep(i, k) cin >> L[i];
        cin >> a >> b >> c >> d;
        repx(i, k, n) L[i] = (((a * L[i - 2]) % d + (b * L[i - 1]) % d + c) % d) + 1;
        rep(i, k) cin >> H[i];
        cin >> a >> b >> c >> d;
        repx(i, k, n) H[i] = (((a * H[i - 2]) % d + (b * H[i - 1]) % d + c) % d) + 1;
        
        cout << "Case #" << C + 1 << ": " << ans << '\n';
    }
}