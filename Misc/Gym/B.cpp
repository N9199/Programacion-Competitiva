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
#define debugm(m)              \
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

struct tarjanSCC
{
    vector<int> _stack, ids, low;
    vector<bool> instack;
    vector<vector<int>> *g;
    int n, ID, count;
    void dfs(int u)
    {
        ids[u] = low[u] = ID++;
        instack[u] = true;
        _stack.push_back(u);
        for (int v : (*g)[u])
        {
            if (ids[v] == -1)
            {
                dfs(v);
                low[u] = min(low[v], low[u]);
            }
            else if (instack[v])
            {
                low[u] = min(low[v], low[u]);
            }
        }
        if (low[u] == ids[u])
        {
            // u is the root of a SCC
            // ** here you can do whatever you want
            // with the SCC just found
            count++;
            // remove SCC from top of the stack
            while (1)
            {
                int x = _stack.back();
                _stack.pop_back();
                instack[x] = false;
                if (x == u)
                    break;
            }
        }
    }
    tarjanSCC(vector<vector<int>> &_g)
    {
        g = &_g;
        n = _g.size();
        _stack.reserve(n);
        ids.assign(n, -1);
        low.resize(n);
        instack.assign(n, 0);
        ID = 0;
        count = 0;
        rep(u, n) if (ids[u] == -1) dfs(u);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n * m);
    vector<char> h(n);
    rep(i, n) cin >> h[i];
    vector<char> v(m);
    rep(i, m) cin >> v[i];
    rep(i, n * m)
    {
        int x = i % m;
        int y = i / m;
        if (h[y] == '<')
        {
            if (x > 0)
                g[i].eb(i - 1);
        }
        else
        {
            if (x < m - 1)
                g[i].eb(i + 1);
        }
        if (v[x] == '^')
        {
            if (y > 0)
                g[i].eb(i - m);
        }
        else
        {
            if (y < n - 1)
                g[i].eb(i + m);
        }
    }

    tarjanSCC s(g);
    if (s.count == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}