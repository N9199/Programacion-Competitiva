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
#define invrep(i, a, n) for (int i = n; i >= (int)a; --i)
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
    for (auto &v : m)         \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

graph g;
vi visited;

pair<int, bool> dfs(int u)
{
    if (visited[u])
        return {0, false};
    debugx(u);
    if (g[u].size() == 2)
    {
        int temp1 = dfs(g[u][0]).first;
        int temp2 = dfs(g[u][1]).first;
        if (temp1 >= temp2)
            return {temp1 + 1, false};
        else
            return {temp2 + 1, true};
    }
    if (g[u].size())
        return {dfs(g[u][1]).first + 1, false};

    return {0, false};
}

void visit(int u)
{
    debugx(u);
    debugv(visited);
    if (visited[u] and g[u].size() > 1)
    {
        for (auto v : g[u])
        {
            if (!visited[v])
                visit(v);
        }
    }
    if (!visited[u])
    {
        if (g[u].size())
        {
            if (dfs(u).second)
                visit(g[u][1]);
            else
                visit(g[u][0]);
        }
        visited[u] = 1;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int size = 1 + (1 << (n - 1));
    int temp = 1;
    repx(i, 1, n)
    {
        size += temp * 3;
        temp *= 2;
    }
    g.resize(size);
    visited.assign(size, 0);
    rep(i, (1 << (n - 1)))
    {
        g[i].eb((1 << (n - 1)) + (i / 2));
        g[i].eb((1 << (n - 1)) + (1 << (n - 2)) + (i / 2));
    }
    int pos = 1 << (n - 1);
    invrep(i, 1, n)
    {
        temp /= 2;
        rep(j, temp)
        {
            g[pos + j].eb(pos + 3 * temp + j / 2);
            g[pos + j].eb(pos + 2 * temp + j);
            g[pos + temp + j].eb(pos + 2 * temp + j);
            g[pos + 2 * temp + j].eb(pos + 3 * temp + temp / 2 + j / 2);
        }
        pos += 3 * temp;
    }
    debugm(g);
    rep(i, k)
    {
        cin >> temp;
        visit((temp - 1) / 2);
    }
    debugx("Hola4");
    int ans = 0;
    for (auto c : visited)
        ans += c;
    cout << ans << '\n';
}