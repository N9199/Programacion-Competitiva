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
#define pb push_back

class Dinic {
    struct edge {
        int to, rev;
        ll f, cap;
    };
 
    vector<vector<edge> > g;
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
    int m,n;
    int a,b;
    while(cin>>m>>n){
        Dinic G = Dinic(n);
        cout<<"S:"<<m<<n;
        vp g;
        set<int> S;
        rep(i,n){
            cin>>a>>b;
            S.insert(a);
            S.insert(b);
            g.emplace_back(a,b);
        }
        set<int>:: iterator it;
        vi temp;
        for( it = S.begin(); it!=S.end(); ++it){
            temp.pb(*it);
        }
        sort(temp.begin(), temp.end());
        map<int, int> nod;
        rep(i,temp.size()){
            nod[temp[i]]=i;
        }
        rep(i,g.size()){
            if(g[i].first==0){
                G.add_edge(nod[g[i].first],nod[g[i].second], 1);
            }else{
                G.add_edge(nod[g[i].first],nod[g[i].second], 1e9);
            }
        }
        cout << G.max_flow(0,m) << endl;
    }
    return 0;
}