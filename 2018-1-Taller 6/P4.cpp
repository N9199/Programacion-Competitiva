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
#define invrep(i,n) for(int i=n;i--;)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

wgraph g;
vi cost;
vi visited;
vi friends;

void dfs(par u){
    for(auto v : g[u.first]){
        if(!visited[v.first]){
            visited[v.first] = 1;
            cost[v.first] = cost[u.first] + v.second;
            cost[u.first] = 0;
            dfs(v);
        }
    }
}

int main(){
    int n,f;
    cin>>n>>f;
    g.resize(n);
    cost.assign(n, 0);
    visited.assign(n, 0);
    friends.assign(n, 0);
    int a,b,c;
    rep(notimportant, n-1){
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    int temp;
    rep(notimportant, f){
        cin>>temp;
        friends[temp] = 1;
    }
        
    visited[1] = 1;
    dfs(par(1, 0));




    return 0;
}