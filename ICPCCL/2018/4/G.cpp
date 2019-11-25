#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<char > vi;
typedef vector<par > vp;
typedef vector<vi > graph;
                            
typedef vector<vp > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl

#define pb push_back
#define eb emplace_back

graph g;
int m,n;
char l,w;

int dfs(int x, int y, int count){
    int ans = count;
    cerr<<x<<' '<<y<<' '<<g[x][y]<<'\n';
    assert(g[x][y] == l);
    g[x][y] = w;
    if(g[x][(y+1)%n] == l)
        ans += dfs(x, (y+1)%n, 1);
    if(g[x][(y+n-1)%n] == l)
        ans += dfs(x, (y+n-1)%n, 1);
    if(x > 0 and g[x-1][y] == l)
        ans += dfs(x-1, y, 1);
    if(x + 1 < m and g[x+1][y] == l)
        ans += dfs(x+1, y, 1);

    return ans;
}

void print(){
    rep(i, m){
        rep(j, n)
            cout<<g[i][j];
        cout<<'\n';
    }
}

int main(){
    while(cin>>m>>n){
        g.assign(m, vi(n, 'a'));
        rep(i, m)
            rep(j, n) 
                cin>>g[i][j];
        
        int x,y;
        cin>>x>>y;
        l = g[x][y];
        w = l + 1;
        dfs(x, y, 1);
        //print();
        int max_c = 0;
        rep(i, m) rep(j, n)
            if(g[i][j] == l)
                max_c = max(max_c, dfs(i, j, 1));
        //print();
        cout<<max_c<<'\n';
    }
    return 0;
}
