#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

// Reps are inclusive exclusive (i.e. range is [a,b))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

// Base two log for ints and for ll
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

// Or LLONG_MAX for ll
#define INF INT_MAX

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m)                                  \
    cerr << #m << ":" << endl;                     \
    for (auto it = m.begin(); it != m.end(); it++) \
    {                                              \
        cerr << distance(m.begin(), it) << ":";    \
        for (auto e : *it)                         \
            cerr << " " << e;                      \
        cerr << endl;                              \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, " ")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

vector<set<int>> g;
vector<umap<int, int>> gv;
string s;
graph a;
string temp = "abcdefghijklmnopqrstuvwxyz";

bool dfs(int u, vi &visited, vi &recStack)
{
    visited[u] = 1;
    recStack[u] = 1;
    for (auto v : g[u])
    {
        if (!visited[v])
        {
            if (dfs(v, visited, recStack))
                return true;
        }
        else if (recStack[v])
            return true;
    }
    recStack[u] = 0;
    return false;
}

void dp(int u, vi &visited)
{
    if (visited[u])
        return;
    visited[u] = 1;
    for (auto v : g[u])
    {
        dp(v, visited);
        rep(i, 26)
        {
            a[u][i] += a[v][i];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.assign(n, set<int>());
    cin >> s;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace(v);
    }
    vi visited(n, 0);
    vi recStack(n, 0);
    rep(i, n)
    {
        if (!visited[i])
            if (dfs(i, visited, recStack))
            {
                cout << -1 << '\n';
                return 0;
            }
    }
    a.assign(n, vi(26, 0));
    rep(i, n) rep(j, 26)
    {
        a[i][j] = s[i] == (j + 'a');
    }
    debugm(a);
    visited.assign(n, 0);
    int ans = 0;
    rep(i, n) dp(i, visited);
    rep(i, n) rep(j, 26)
    {
        ans = max(ans, a[i][j]);
    }
    cout << ans << '\n';
    debugm(a);
}