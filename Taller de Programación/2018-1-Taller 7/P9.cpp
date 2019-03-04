#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,ll> ilpar;

#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define gcd __gcd
#define eb emplace_back
#define pb push_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout<<endl
#define debugv(v) //cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl

struct par{
    ll first, second;
    par(int first, int second): first(first), second(second) {}
    bool operator< (const par& y) const{
        return first > y.first;
    }
};

struct pair_hash {
    inline size_t operator()(const pair<int, int> & v) const {
        return v.first*31+v.second;
    }
};

typedef vector<par> vp;
typedef vector<vp > wgraph;
class Almost{
    int n;
    wgraph g1,g2,g3;
    vi c1, c2;
    unordered_set<pair<int, int>, pair_hash> marked;

    void build(int s, int t){
        c1[s] = 0;
        c2[t] = 0;
        debugx(s);
        debugx(t);
        priority_queue<par> q;
        q.emplace(0, s);
        while(!q.empty()){
            par u = q.top(); q.pop();
            for(auto v : g1[u.second]){
                //debugp(v);
                if(v.first+u.first < c1[v.second]){
                    c1[v.second] = v.first+u.first;
                    //cerr<<v.second<<": "<<c1[v.second]<<endl;
                    q.emplace(c1[v.second], v.second);
                }
            }
        }
        while(!q.empty()){
            q.pop();
        }
        assert(q.empty());
        debugx("");
        q.emplace(0, t);
        while(!q.empty()){
            par u = q.top(); q.pop();
            for(auto v : g2[u.second]){
                debugp(v);
                if(v.first+u.first < c2[v.second]){
                    c2[v.second] = v.first+u.first;
                    //cerr<<v.second<<": "<<c2[v.second]<<endl;
                    q.emplace(c2[v.second], v.second);
                }
            }
        }

        queue<int> q2;
        q2.emplace(s);
        vi visited(n, 0);
        visited[s] = 1;
        while(!q2.empty()){
            int u = q2.front(); q2.pop();
            for(auto v : g1[u]){
                //debugp(v);
                if(!visited[v.second]){
                    q2.emplace(v.second);
                    visited[v.second] = 1;
                }
                if(c1[u]+v.first+c2[v.second] == c1[t]){
                    marked.emplace(u, v.second);
                    //cerr<<c1[u]<<" "<<v.first<<" "<<c2[v.second]<<endl;
                }
            }
        }
        //assert(!marked.empty());
        assert(c1[t]==c2[s]);
        assert(c1[s]==c2[t]);
        debugx("Build");
        rep(u, g1.size()){
            for(auto v : g1[u]){
                if(marked.find(pair<int, int>(u, v.second)) == marked.end())
                    g3[u].eb(v);
            }
        }
    }

public:
    Almost(int n){
        this->n=n;
        g1.resize(n);
        g2.resize(n);
        g3.resize(n);
        c1.assign(n, 1e9);
        c2.assign(n, 1e9);
    }

    void add_edge(int u, int v, int p){
        g1[u].eb(p,v);
        g2[v].eb(p,u);
    }

    int dijsktra(int s, int t){
        build(s, t);
        debugv(c1);
        debugv(c2);
        if(c1[t]==(int)1e9 or c2[s]==(int)1e9) return -1;
        priority_queue<par> q;
        vi visited(n, 1e9);
        q.emplace(0,s);
        while(!q.empty()){
            par u = q.top(); q.pop();
            debugp(u);
            if(u.second == t) return u.first;

            for(auto v : g3[u.second]){
                if(v.first+u.first<visited[v.second]){
                    visited[v.second] = v.first+u.first;
                    q.emplace(v.first+u.first, v.second);
                }
            }
        }
        return -1;
    }

};


int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==m and n==0) break;
        Almost a(n);
        int s,t;
        cin>>s>>t;
        rep(_,m){
            int u,v,p;
            cin>>u>>v>>p;
            a.add_edge(u,v,p);
        }
        cout<<a.dijsktra(s,t)<<"\n";
        debugx("Hola");
    }
    //cout<<"Hola";
    return 0;
}