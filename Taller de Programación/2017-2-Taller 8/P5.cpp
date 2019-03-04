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
#define pb push_back

void dfs(graph &g, int start, vi &dist)
{
    int inf = 1e9;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (dist[v] == inf)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}

int main()
{

    return 0;
}