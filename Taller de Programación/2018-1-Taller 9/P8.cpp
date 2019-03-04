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
#define debugx(x) cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))

ll func(ll n){
    //debugx(n);
    if(n <= 0) return 0;
    ll temp = func(n-(1ll<<lgg(n))) + (n-(1ll<<lgg(n))+1);
    if(lgg(n) > 0)
        return temp + (((ll)lgg(n))<<(lgg(n)-1));
    else
        return temp;
}


ll func(ll a, ll b){
    return func(b)-func(a-1);
}
int main(){
    ll a,b;
    while(cin>>a>>b){
        cout<<func(a,b)<<"\n";
    }
    return 0;
}