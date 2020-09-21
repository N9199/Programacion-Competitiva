#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
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

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) //cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v) //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m) //              \
    cerr << #m << ":" << endl; \
    for (auto v : m)           \
    {                          \
        for (auto e : v)       \
            cerr << " " << e;  \
        cerr << endl;          \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

bool dfs(int u, graph &g, vi &visited, int id)
{
    visited[u] = id;
    for (auto v : g[u])
        if (visited[v] == -1)
        {
            if (dfs(v, g, visited, id + 1))
                return true;
        }
        else if (visited[v] < id)
            return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n);
    graph invg(n);
    int u, v;
    rep(i, m)
    {
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        invg[v].eb(u);
    }
    vi visited(n, -1);
    debugx("Hi");
    debugm(g);
    if (dfs(0, g, visited, 1))
    {
        cout << "-1\n";
        return 0;
    }
    debugx("Hi2");
    vi ans(n, 0);
    umap<int, char> f;
    f[0] = 'E';
    f[1] = 'A';
    rep(i, n) if (invg[i].size() == 0) ans[i] = 1;
    rep(i, n) if (ans[i] == 0) break;
    else if (i == n - 1) ans[i] = 0;
    rep(i, n) cout << f[ans[i]];
    cout << '\n';
}