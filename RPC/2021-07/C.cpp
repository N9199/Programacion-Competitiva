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
unordered_map<string, int> d;
unordered_map<string, string> g;
int dfs(const string &u)
{
    if (g[u] == "")
        return 0;
    //debugx(u);
    //debugx(d[u]);
    //debugx(g[u]);
    //debugx(d[g[u]]);
    if (d[g[u]] > 0)
    {
        if (d[u] > d[g[u]])
            return d[u] - d[g[u]] + 1;
        return 0;
    }
    d[g[u]] = d[u] + 1;
    return dfs(g[u]);
}
int main()
{
    int n;
    cin >> n;
    unordered_set<string> s;
    string s1, s2;
    rep(i, n)
    {
        cin >> s1 >> s1 >> s2;
        g[s1] = s2;
        s.emplace(s1);
        s.emplace(s2);
    }
    int out = 0;
    for (auto &u : s)
    {
        if (d[u] > 0)
            continue;
        d[u] = 1;
        out = max(dfs(u), out);
    }
    //debugv(g);
    //debugv(d);
    if (out == 0)
        cout << "No trades possible\n";
    else
        cout << out << '\n';
}