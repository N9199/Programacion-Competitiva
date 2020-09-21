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
    int t;
    cin >> t;
    int n, u;
    int l, r, val;
    int q, i;
    int a[10000];
    rep(_, t)
    {
        cin >> n >> u;
        memset(a, 0, sizeof(a));
        rep(__, u)
        {
            cin >> l >> r >> val;
            a[l] += val;
            if (r + 1 < n)
                a[r + 1] -= val;
        }
        repx(i, 1, n) a[i] += a[i - 1];
        cin >> q;
        rep(__, q)
        {
            cin >> i;
            cout << a[i] << '\n';
        }
    }
}