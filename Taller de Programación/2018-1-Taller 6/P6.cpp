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

graph g((int)1e4+1);

int bfs(int start, int end){
    vi dist((int)1e4+1, -1);

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()){
        int u = q.front();
        //cout<<"u: "<<u<<endl;
        q.pop();
        if(u == end)
            return dist[end];
        for(int v : g[u]){
            if(dist[v] == -1){
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist[end];
}

int main(){
    repx(i,1,1e4+1){
        if(2*i<=1e4)
            g[i].pb(2*i);
        g[i].pb(i-1);
    }
    int n,m;
    cin>>n>>m;
    cout<<bfs(n,m)<<endl;
    return 0;
}