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
#define repx(i,x,n) for(int i=x; i<(int)n;++i)
#define invrep(i,n) for(int i=n;i--;)
#define pb push_back

vp comp;
graph dp = graph(10000,vi(200,-1));
vi check;
int d,p;
int func(int c, int i){
    //cout<<"func("<<c<<","<<i<<")"<<endl;
    if(i<0){
        return 0;
    }
    if(dp[c][i]!=-1){
        return dp[c][i];
    }
    if(c>=comp[i].second){
        return dp[c][i]=max(comp[i].first+func(c-comp[i].second,i-1),func(c,i-1));
    }else{
        return dp[c][i]=func(c,i-1);
    }
}

struct edge
{
    int u,v; ll w;
    edge(int u, int v, ll w) : u(u), v(v), w(w) {}

    bool operator< (const edge &o) const
    {
        return w < o.w;
    }
};

struct UnionFind
{
    vector<int> P,rank;

    UnionFind(int N)
    {
        P.resize(N); for(int i = 0; i < N; ++i) P[i] = i;
        rank.assign(N,0);
    }

    int findSet(int u)
    {
        return u == P[u] ? u : P[u] = findSet(P[u]);
    }

    bool isSameSet(int u, int v)
    {
        return findSet(u) == findSet(v);
    }

    void joinSets(int u, int v)
    {
        if(isSameSet(u,v)) return;
        u = findSet(u); v = findSet(v);

        if(rank[u] < rank[v]) P[u] = v;
        else
        {
            P[v] = u;
            if(rank[u] == rank[v]) ++rank[u];
        }
    }
};


int main(){
    int r,b;
    while(cin>>d>>p>>r>>b){
        check = vi(d+p);
        vi price = vi(d+p);
        rep(i,d+p){
            cin>>price[i];
        }
        UnionFind U(d+p);
        rep(i,r){
            int a,b;
            cin>>a>>b;
            U.joinSets(a-1,d+b-1);
        }
        comp = vp(d+p,par(0,0));
        rep(i,d+p){
            comp[U.findSet(i)].first+= i < d ? -1 : 1;
            comp[U.findSet(i)].second+=price[i];
        }
        /*for(auto p : comp){
            cout<<"comp:"<<p.first<<" "<<p.second<<endl;
        }*/
        
        //bfs(g,price);
        //rep(i,comp.size()) cout<<"comp: "<<comp[i].first<<" "<<comp[i].second<<endl;
        cout<<d+func(b,comp.size()-1)<<" ";
        rep(i,comp.size()){
            comp[i].first*=-1;
            //cout<<"comp: "<<comp[i].first<<endl;
        }
        dp = graph(10000,vi(200,-1));
        cout<<p+func(b,comp.size()-1)<<"\n";
        dp = graph(10000,vi(200,-1));
        comp = vp();
        //cout<<"HI"<<endl;
    }
    return 0;
}