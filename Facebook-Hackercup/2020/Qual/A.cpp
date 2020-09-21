#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
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
#define gcd __gcd

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

int visited[50][50];

void dfs(int u, int i, graph &g)
{
    visited[i][u] = 1;
    for (auto v : g[u])
        if (!visited[i][v])
            dfs(v, i, g);
}

int main()
{
    int t;
    cin >> t;
    vector<char> m = {'N', 'Y'};
    rep(c, t)
    {
        int n;
        cin >> n;
        graph g(n);
        memset(visited, 0, sizeof(visited));
        vi I(n);
        rep(i, n)
        {
            char c;
            cin >> c;
            I[i] = (c == 'Y');
        }
        vi O(n);
        rep(i, n)
        {
            char c;
            cin >> c;
            O[i] = (c == 'Y');
        }
        rep(i, n) if (O[i])
        {
            if (i > 0 and I[i - 1])
                g[i].eb(i - 1);
            if (i < n - 1 and I[i + 1])
                g[i].eb(i + 1);
        }
        rep(i, n) dfs(i, i, g);

        std::cout << "Case #" << c + 1 << ": \n";
        rep(i, n)
        {
            rep(j, n) std::cout << m[visited[i][j]];
            std::cout << '\n';
        }
    }
}