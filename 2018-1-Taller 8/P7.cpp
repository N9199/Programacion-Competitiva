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
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a,b;
    vp graph(n+1);
    vi indegree(n+1,0);
    int s=0, t=2*n+1;

    repx(i,1,n+1){
        cin>>a>>b;
        indegree[a]++;
        indegree[b]++;
        graph[i]=par(a,b);
    }
    int count=0;
    repx(w,1,n+1){
        if(indegree[w]<2){
            count++;
            continue;
        }
        int wa=graph[w].first, wb=graph[w].second;
        Dinic din(2*n+2);
        repx(i,1,n+1){
            int a=graph[i].first, b=graph[i].second;
            if(i==w or a==w or b==w) continue;
            din.add_edge(s, i, 1);
            din.add_edge(i, n+a, 1);
            din.add_edge(i, n+b, 1);
        }
        repx(i,1,n+1){
            if(i==w) continue;
            if(i==wa or i==wb)
                din.add_edge(n+i, t, indegree[w]-2);
            else
                din.add_edge(n+i, t, indegree[w]-1);
        }
        int votes = n-1-indegree[w];
        int goodvotes = din.max_flow(s,t);
        if(votes > goodvotes) count++;
    }
    cout<<count<<endl;

    return 0;
}