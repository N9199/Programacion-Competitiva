#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

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
    int n, c, d;
    int d1, d2;
    vi parent;
    vi level;
    vi root;
    vvi P;
public:
    LcaTree(int n){
        this->n = n;
        this->c = 4;
        this->d = 2;
        this->d1 = 2;
        this->d2 = 4;
        parent.assign(n,-1);
        level.assign(n,-1);
        P.assign(n,vi(Log2(n)+1,-1));
        root.assign(n,-1);
    }
    int addLeaf(int par){
        addLeaf(++c, par);
        addLeaf(++c, par);
        int m1 = lca(c, d1);
        int m2 = lca(c, d2);
        if(d<level[c]+max(level[d1]-2*level[m1],level[d2]-2*level[m2])){
            d = level[c]+max(level[d1]-2*level[m1], level[d2]-2*level[m2]);
            bool s = (d == level[c]+level[d1]-2*level[m1]);
            d1 = s?d1:c;
            d2 = s?c:d2;
            //cout<<d1<<" "<<d2<<endl;
        }
        return d;
    }
    void addLeaf(int index, int par){
        parent[index] = par;
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
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>q;
    LcaTree tree(2*q+5);
    tree.addRoot(1);
    repx(i,2,5)
        tree.addLeaf(i,1);
    int temp;
    rep(notimportant,q){
        cin>>temp;
        cout<<tree.addLeaf(temp)<<'\n';
    }

    return 0;
}