#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<unordered_set<int>> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (size_t i = b; i-- > (size_t)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, " ")), cout << '\n'

//función auxiliar requerida
void dfs_ts(graph &g, int u, vector<bool> &vis, vector<int> &ts)
{
    vis[u] = true;
    for (int v : g[u])
        if (not vis[v])
            dfs_ts(g, v, vis, ts);
    ts.pb(u);
}

//ts parte vacío y termina con el toposort
void toposort(graph &g, vector<int> &ts)
{
    int n = g.size();
    vector<bool> vis(n, false);
    rep(u, n) if (not vis[u])
        dfs_ts(g, u, vis, ts);
    //reverse(ts.begin(), ts.end());
}

bool dfs(graph &g, int start)
{
    stack<int> s;
    s.emplace(start);
    bool visited[g.size()];
    rep(i, g.size()){
        visited[i] = true;
    }
    visited[start] = false;
    while (!s.empty())
    {
        int u = s.top();
        debugx(u);
        s.pop();
        for (int v : g[u])
        {
            if (visited[v])
            {
                visited[v] = false;;
                s.emplace(v);
                debugx(v);
            }
            else
                return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> vs(n);
    rep(i, n) cin >> vs[i];

    graph g(26);
    repx(i, 1, n)
    {
        rep(j, min(vs[i - 1].size(), vs[i].size()))
        {
            if (vs[i][j] == vs[i - 1][j])
                continue;
            else
            {
                g[vs[i][j] - 'a'].insert(vs[i - 1][j] - 'a');
                break;
            }
        }
    }
    vi visited;
    rep(i, 26)
    {
        visited.assign(26, 1);
        if (dfs(g, i))
        {
            cout << "Impossible\n";
            return 0;
        }
        cerr<<'\n';
    }

    vi order;
    toposort(g, order);

    rep(i, order.size()) cout << (char)(order[i] + 'a');
    cout << '\n';

    return 0;
}
