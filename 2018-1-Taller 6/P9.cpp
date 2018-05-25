#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,int> par;
typedef pair<int,ll> ilpar;
typedef vector<par> vp;

#define eb emplace_back
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back

int inline Log2(unsigned int x){
    return 31 - __builtin_clz(x);
}
int inline Log2ll(unsigned long long  x){
    return 63 - __builtin_clzll(x);
}

class LcaTree
{
    int n,d;
    int d1,d2;
    vi parent;
    vi dp;
    vi rks;
    vvi kids;
    vvi g;
    vi level;
    vi root;
    vvi P;
public:
    LcaTree(vvi g){
        this->n = g.size();
        this->g = g;
        parent.assign(n,-1);
        kids.resize(n);
        level.assign(n,-1);
        P.assign(n,vi(Log2(n)+1,-1));
        root.assign(n,-1);
        vi visited(n);

        int u = 1;
        addRoot(u);
        queue<int> q;
        q.emplace(u);
        visited[u] = 1;
        while(!q.empty()){
            u = q.front(); q.pop();
            for(int v : g[u]){
                if(!visited[v]){
                    q.emplace(v);
                    visited[v]=1;
                    addLeaf(v,u);
                    //cout<<u<<" "<<v<<endl;
                }
            }
        }
        rks.assign(n, -1);
        dp.assign(n, -1);
        diameter(1);
        this->d = rks[1];
        this->d1 = u;
        this->d2 = find(d1);
    }
    int find(int u){
        queue<int> q;
        q.emplace(u);
        vi visited(n);
        visited[u] = 1;
        while(!q.empty()){
            u = q.front(); q.pop();
            for(int v : g[u]){
                if(!visited[v]){
                    q.emplace(v);
                    visited[v]=1;
                }
            }
        }
        return u;
    }
    int diameter(int u){
        if(dp[u]!=-1)
            return dp[u];
        int m1 = 0;
        int m2 = 0;
        for(int v: kids[u]){
            int temp = diameter(v);
            if(m1<temp){
                m2 = m1;
                m1 = temp;
            }else if(m2<temp){
                m2 = temp;
            }
        }
        rks[u] = m1+m2;
        return dp[u]=m1+1;
    }
    int query(int u, int dist){
        if(dist>d)
            return 0;
        int m1 = lca(u, d1);
        int m2 = lca(u, d2);
        if(dist>level[u]+max(level[d1]-2*level[m1],level[d2]-2*level[m2]))
            return 0;
        int m = level[u]+max(level[d1]-2*level[m1], level[d2]-2*level[m2]);
        bool s = (m == level[u]+level[d1]-2*level[m1]);
        if(dist>level[u]-level[s?m1:m2]){
            dist = m - dist;
            u = s?d1:d2;
        }else if(dist == m){
            return s?m1:m2;
        }
        while(dist != 0){
            int raise = Log2(dist);
            u = P[u][raise];
            dist -= (1<<raise);
        }
        return u;
    }

    void addLeaf(int index, int par){
        parent[index] = par;
        kids[par].eb(index);
        level[index] = level[par] + 1;
        P[index][0] = par;
        root[index] = root[par];
        for(int j=1; (1<<j) < n; ++j){
            if(P[index][j-1] != -1)
                P[index][j] = P[P[index][j-1]][j-1];
        }
    }
    void addRoot(int index){
        parent[index] = index;
        level[index] = 0;
        root[index] = index;
    }
    int lca(int u, int v){
        if(root[u] != root[v] || root[u] == -1)
            return -1;
        if(level[u] < level[v])
            swap(u,v);
        int dist = level[u] - level[v];
        while(dist != 0){
            int raise = Log2(dist);
            u = P[u][raise];
            dist -= (1<<raise);
        }
        if(u == v)
            return u;
        for(int j = Log2(n); j>=0; --j){
            if(P[u][j] != -1 && P[u][j] != P[v][j]){
                u=P[u][j];
                v=P[v][j];
            }
        }
        return parent[u];
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    vvi g(n+1);
    rep(notimportant, n-1){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    LcaTree tree(g);
    rep(notimportant, q){
        int u,d;
        cin>>u>>d;
        cout<<tree.query(u,d)<<'\n';
    }
}