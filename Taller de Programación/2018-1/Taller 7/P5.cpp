#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,int> par;
typedef pair<int,ll> ilpar;



#define eb emplace_back
#define rep(i,n) for(int i=0;i<n;++i)

int inline Log2(unsigned int x){
    return 31 - __builtin_clz(x);
}
int inline Log2ll(unsigned long long  x){
    return 63 - __builtin_clzll(x);
}

struct trip{
    int a;
    int b;
    ll w;
    trip(){}
    trip(int a,int b,ll w): a(a),b(b),w(w){}
    bool operator< (const trip& y) const{
        return w > y.w;
    }
};

class LcaTree
{
public:
    int n;
    vi parent;
    vi level;
    vi root;
    vvi P;
    vvl W;
public:
    LcaTree(int n){
        this->n = n;
        parent.assign(n,-1);
        level.assign(n,-1);
        P.assign(n,vi(Log2(n)+1,-1));
        W.assign(n,vl(Log2(n)+1,-1));
        root.assign(n,-1);
    }
    void addLeaf(int index, int par, ll weight){
        parent[index] = par;
        level[index] = level[par] + 1;
        P[index][0] = par;
        W[index][0] = weight;
        root[index] = root[par];
        for(int j=1; (1<<j) < n; ++j){
            if(P[index][j-1] != -1){
                P[index][j] = P[P[index][j-1]][j-1];
                W[index][j] = max(W[P[index][j-1]][j-1],W[index][j-1]);
            }
            //else
                //break;
        }
    }
    void addRoot(int index){
        parent[index] = index;
        level[index] = 0;
        root[index] = index;
    }
    ilpar lca(int u, int v){
        if(root[u] != root[v] || root[u] == -1)
            return ilpar(-1,-1);
        if(level[u] < level[v])
            swap(u,v);
        int dist = level[u] - level[v];
        ll maxw = 0;
        while(dist != 0){
            int raise = Log2(dist);
            maxw = max(W[u][raise],maxw);
            u = P[u][raise];
            dist -= (1<<raise);
        }
        if(u == v)
            return ilpar(u,maxw);
        for(int j = Log2(n); j>=0; --j){
            if(P[u][j] != -1 && P[u][j] != P[v][j]){
                maxw = max(max(W[u][j],W[v][j]),maxw);
                u=P[u][j];
                v=P[v][j];
            }
        }
        maxw = max(max(W[u][0],W[v][0]),maxw);
        return ilpar(parent[u],maxw);
    }
};


int main(){
ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<trip> edges(m);
    vvi adj(n);
    rep(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i] = trip(u-1,v-1,w);
        adj[u-1].eb(i);
        adj[v-1].eb(i);
    }
    LcaTree tree(n);
    tree.addRoot(0);
    priority_queue<trip> q;
    for(auto v: adj[0]) q.push(edges[v]);
    ll total = 0;
    //prim!
    while(!q.empty()){
        trip e = q.top();q.pop();
        if(tree.root[e.a]==-1){
            tree.addLeaf(e.a,e.b,e.w);
            total += e.w;
            for (auto v: adj[e.a]) q.push(edges[v]);
        }
        else if(tree.root[e.b]==-1){
            tree.addLeaf(e.b,e.a,e.w);
            total += e.w;
            for (auto v: adj[e.b]) q.push(edges[v]);
        }
    }
    int z;
    cin>>z;
    rep(i,z){
        int u,v;
        cin>>u>>v;
        u--;v--;
        ll w = 0;
        for(auto k: adj[u]) if(edges[k].a == v || edges[k].b == v) w=edges[k].w;
        ilpar res = tree.lca(u,v);
        cout<< total - res.second + w <<endl;
    }
}