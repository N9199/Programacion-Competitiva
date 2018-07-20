#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int > vi;
typedef vector<par > vp;
typedef vector<vi > graph;
                            
typedef vector<vp > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

vi good;
vi visited;
vi used;
int cnt = 0;

void dfs(graph &g, int v){
    visited[v] = 1;
    good[v] = 1;
    for(auto u : g[v]){
        if(visited[u] != -1)
            dfs(g, u);
    }
}

void dfs2(graph &g, int v){
    used[v] = 1;
    cnt++;
    for(auto u : g[v]){
        if(used[u] != 1 and good[u] != 1)
            dfs2(g, u);
    }
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    graph g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g[--a].pb(--b);
    }
    vp val;
    good.assign(n, -1);
    visited.assign(n, -1);
    dfs(g, s);
    rep(i,n){
        if(good[i] != 1){
            cnt = 0;
            used.assign(n, 0);
            dfs2(g, i);
            val.eb(cnt, i);
        }
    }
    sort(val.begin(), val.end());
    reverse(val.begin(), val.end());
    int ans = 0;
    for(auto u : val){
        if(good[u.second] != 1){
            ans++;
            dfs(g, u.second);
        }
    }
    cout<<ans<<"\n";
    return 0;
}