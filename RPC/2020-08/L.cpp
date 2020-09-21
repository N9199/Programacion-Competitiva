#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, ll> par;
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
    os << p.first << ' ' << p.second;
    return os;
}

static inline uint32_t rotr32(uint32_t n, unsigned int c)
{
    const unsigned int mask = (CHAR_BIT * sizeof(n) - 1);

    c &= mask;
    return (n >> c) | (n << ((-c) & mask));
}

int ans[32];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    uint32_t n;
    int c;
    rep(_, t)
    {
        memset(ans, 0, sizeof(ans));
        c = 0;
        cin >> n;
        rep(_, 32)
        {
            ans[n % 32] = 1;
            n = rotr32(n, 1);
        }
        rep(i, 32) c += ans[i];
        if (c == 32)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}