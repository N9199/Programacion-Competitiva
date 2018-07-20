#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, int> par;
typedef vector<int > vi;
typedef vector<ll > vll;
typedef vector<par > vp;
typedef vector<vi > graph;
                            
typedef vector<vp > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout<<endl
#define debugv(v) //cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))

#define int ll


wgraph g;
vll cost;
vi parent;
int n, m;
void dijsktra(){
    priority_queue<par, vp, greater<par> > q;
    q.emplace(0, 0);
    while(!q.empty()){
        int u = q.top().second;
        if(u == n-1)
            debugx(u);
        ll w = q.top().first; q.pop();
        for(auto v : g[u]){
            if(v.second == 0)
                continue;
            //debugp(v);
            if(cost[v.second] > w + v.first){
                parent[v.second] = u;

                cost[v.second] = w + v.first;
                q.emplace(cost[v.second], v.second);
            }
        }
    }
}
#undef int
int main(){
#define int ll
    cin>>n>>m;
    g.resize(n);
    cost.assign(n, 1e12);
    parent.assign(n, -1);

    rep(i,m){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        g[a].eb(c,b);
        g[b].eb(c,a);
    }
    dijsktra();
    if(parent[n-1] == -1){
        cout<<-1<<'\n';
        return 0;
    }
    int current = n-1;
    vi a;
    while(current != 0){
        a.pb(current);
        current = parent[current];
    }
    a.pb(0);
    for(int i = a.size()-1; i >= 0; i--){
        cout<<a[i]+1ll;
        if(i>0)
            cout<<" ";
    }
    
    return 0;
}