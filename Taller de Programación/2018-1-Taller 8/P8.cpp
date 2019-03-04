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

#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define gcd __gcd
#define eb emplace_back
#define pb push_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout<<endl
#define debugv(v) //cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl

class Dinic {
    struct edge {
        int to, rev;
        ll f, cap;
    };
 
    vector<vector<edge>> g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;
 
    bool bfs(int start, int finish) {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail) {
            int u = q[head++];
            for (const edge &e : g[u]) {
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap) {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }
 
    ll dfs(int u, ll f) {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i) {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }
 
public:
    Dinic(int n) {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }
 
    void add_edge(int u, int v, ll cap) {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
        g[u].pb(a);
        g[v].pb(b);
    }
 
    ll max_flow(int source, int dest) {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest)) {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};

int main(){
    int n;
    while(cin>>n){
        vector<vector<char>> g(n);
        rep(i,n){
            g[i].resize(n);
            rep(j,n)
                cin>>g[i][j];
        }
        vvi c(n,vi(n,-1));
        vvi r(n,vi(n,-1));
        int a1 = 0;
        bool b = false;
        rep(i,n){
            b = false;
            rep(j,n){
                if(g[i][j]=='.'){
                    c[i][j]=a1;
                    b=true;
                }else if(b){
                    b=false;
                    a1++;
                }
            }
            a1++;
        }

        int a2 = 0;
        b = false;
        rep(i,n){
            b = false;
            rep(j,n){
                if(g[j][i]=='.'){
                    r[j][i]=a2;
                    b=true;
                }else if(b){
                    b=false;
                    a2++;
                }
            }
            a2++;
        }
        rep(i,n) {
            debugv(c[i]);
        }
        rep(i,n) {
            debugv(r[i]);
        }
        Dinic din(a1+a2+2);
        rep(i,n) rep(j,n){
            if(c[i][j]!=-1){
                din.add_edge(c[i][j], a1+r[i][j], 1);
                par e(c[i][j],a1+r[i][j]);
                debugp(e);
            }
        }
        rep(i,a1){
            din.add_edge(a1+a2, i, 1);
        }
        rep(i,a2){
            din.add_edge(a1+i, a1+a2+1, 1);
        }
        debugx(a1);
        cout<<din.max_flow(a1+a2, a1+a2+1)<<"\n";
    }
    return 0;
}