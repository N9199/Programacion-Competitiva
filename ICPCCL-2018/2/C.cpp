#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, int> par;
typedef vector<int > vi;
typedef vector<ll > vll;
typedef vector<par > vp;
typedef vector<vi > graph;
                            
typedef vector<vp > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout<<endl
#define debugv(v) //cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))

graph dp(101, vi(100, -1));

int MOD = 1001113;

int func(int n, int k){
    if(dp[n][k] != -1)
        return dp[n][k];
    int out;
    if(n == 0 or k > n or k < 0)
        return 0;
    else if(k == 0)
        return 1;
    else
        out = (((k+1)*func(n-1, k)%MOD)+((n-k)*func(n-1,k-1)%MOD))%MOD;
    
    return dp[n][k] = out;
}

int main(){
    int p;
    cin>>p;
    rep(i, p){
        int k, n, v;
        cin>>k>>n>>v;
        cout<<k<<" "<<func(n, v)<<"\n";
    }
    return 0;
}