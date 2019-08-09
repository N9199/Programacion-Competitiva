#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef pair<par, int> iii;
typedef vector<int > vi;
typedef vector<ll > vll;
typedef vector<par > vp;
typedef vector<vi > graph;

typedef vector<vp > wgraph;

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back
#define umap unordered_ma

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {  
        if (!isSameSet(i, j)) { numSets--;  
        int x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
        else                   { p[x] = y; setSize[y] += setSize[x];
                                if (rank[x] == rank[y]) rank[y]++; } } }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind u(n);
    graph g(n);
    int a,b;
    rep(i, m){
        cin>>a>>b;
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
        u.unionSet(a-1, b-1);
    }
    /*rep(i, n){
        for(auto n : g[i]){
            cout<<n<<" ";
        }
        cout<<endl;
    }*/
    rep(i, n){
        if(g[i].size() != u.sizeOfSet(i) - 1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}