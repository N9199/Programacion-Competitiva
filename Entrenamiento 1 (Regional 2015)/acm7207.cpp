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

void bfs(graph& g, vi& price){
    rep(i,check.size()){
        if(check[i]==-1)
            continue;
        //cout<<"i: "<<i<<endl;
        queue<int> q;
        q.push(i);
        par temp = {0,0};
        int t=1;
        if(i>=d){
            t*=-1;
        }
        //cout<<"temp: "<<temp.first<<endl;
        while(!q.empty()){
            int u = q.front(); q.pop();
            //cout<<"u: "<<u<<endl;
            for(int v: g[u]){
                //cout<<v<<endl;
                if(check[v]==-1)
                    continue;
                q.push(v);
                //cout<<"t,g: "<<t<<" "<<price[v]<<" v: "<<v<<endl;
                temp.first+=t;
                temp.second+=price[v];
                check[v]=-1;
            }
            t*=-1;
            //cout<<"temp: "<<temp.first<<endl;
        }
        if(g[i].size()==0){
            temp.first+=t;
            temp.second+=price[i];
        }
        comp.pb(temp);
    }
}

int main(){
    int r,b;
    while(cin>>d>>p>>r>>b){
        check = vi(d+p);
        graph g = graph(d+p);
        vi price = vi(d+p);
        rep(i,d+p){
            cin>>price[i];
        }
        rep(i,r){
            int a,b;
            cin>>a>>b;
            g[a-1].pb(d+b-1);
            g[d+b-1].pb(a-1);
        }
        bfs(g,price);
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