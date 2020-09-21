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
#define int ll
struct FenwickTree
{
    vector<ll> FT;
    FenwickTree(int N) { FT.resize(N + 2, 0); }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j) { return query(j) - query(i - 1); }

    void update(int i, int v)
    {
        int s = 0;//query(i, i); // Sets range to v?
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v - s;
    }

    // Queries puntuales, Updates por rango
    void update(int i, int j, int v)
    {
        update(i, v);
        update(j + 1, -v);
    }
};
#undef int
int main()
{
    #define int ll
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    FenwickTree st(n);
    st.update(1, n + 1, c);
    char C;
    int u, v, k;
    rep(_, m)
    {
        cin >> C >> u;
        if (C == 'S')
        {
            cin >> v >> k;
            st.update(u, v, k);
        }
        else
            cout << st.query(u) << '\n';
    }
}

