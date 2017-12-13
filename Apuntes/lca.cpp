//LCA: Lowest common ancestor (componentes no necesariamente conexos)
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define push_back pb

int inline Log2(unsigned int x){
    return 31 - __builtin_clz(x);
}
int inline Log2ll(unsigned long long  x){
    return 63 - __builtin_clzll(x);
}

class LcaTree
{
    int n;
    vi parent;
    vi level;
    vi root;
    vvi P;
public:
    LcaTree(int n){
        this->n = n;
        parent.assign(n,-1);
        level.assign(n,-1);
        P.assign(n,vi(Log2(n)+1,-1));
        root.assign(n,-1);
    }
    void addLeaf(int index, int par){
        parent[index] = par;
        level[index] = level[par] + 1;
        P[index][0] = par;
        root[index] = root[par];
        for(int j=1; (1<<j) < n; ++j){
            if(P[index][j-1] != -1)
                P[index][j] = P[P[index][j-1]][j-1];
            //else
                //break;
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
    LcaTree tree(8);
    tree.addRoot(0);
    tree.addLeaf(1,0);
    tree.addLeaf(2,0);
    tree.addLeaf(3,1);
    tree.addLeaf(4,0);
    tree.addLeaf(5,4);
    tree.addLeaf(6,4);
    tree.addLeaf(7,2);
    for(int i=0;i<8;++i) for(int j=0;j<8;++j){
        cout<<"lca("<<i<<","<<j<<") = "<<tree.lca(i,j)<<endl;
    }
}