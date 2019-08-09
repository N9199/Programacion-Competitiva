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

struct pair_hash {
    inline size_t operator()(const par & v) const {
        return v.first*31+v.second;
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unordered_set<par, pair_hash> us;
    unordered_set<int> fin;
    int n,s;
    cin>>n>>s;
    vvi g(n);
    vi c(n);
    rep(j, n) cin>>c[j];
    int a,b;
    rep(notimportant, s){
        cin>>a>>b;
        g[--a].pb(--b);
        g[b].pb(a);
    }
    queue<par> q;
    rep(i, n){
        q.emplace(i, c[i]);
        us.emplace(i, c[i]);
        debugp(par(i,c[i]));
    }
    while(!q.empty()){
        par u = q.front(); q.pop();
        debugp(u);
        for(int v : g[u.first]){
            par temp(v, __gcd(c[v], u.second));
            
            if(us.find(temp) == us.end()){
                q.emplace(temp);
                us.emplace(temp);
                debugp(temp);
            }
        }
    }
    for(auto p : us) fin.emplace(p.second);
    debugv(fin);

    cout<<fin.size()<<endl;
    return 0;
}