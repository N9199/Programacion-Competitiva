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
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

int main(){
    int n,m;
    cin>>n>>m;
    graph g(n);
    int a,b;
    rep(ignore_me, m){
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    return 0;
}