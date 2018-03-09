#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
vector<ll> p2(54,-1ll);

ll fillp(int x){
    if(x<0)
        return 0ll;
    if(p2[x] != -1ll)
        return p2[x];
    if(x==0)
        return p2[0]=1ll;
    return p2[x]=1ll+2ll*(fillp(x-1)-1ll)+(1ll<<((ll)x-1ll));
}

ll func(ll x){
    ll leftsum = 0;
    ll sum=0;
    for(int i = 53;i>=0;i--){
        ll cmp = 1ll<<i;
        if(x>=cmp){
            x-=cmp;
            sum+=p2[i]+cmp*leftsum;
            leftsum ++;
        }
    }
    return sum;
}

int main(){
    fillp(53);
    ll A,B;
    while(cin>>A>>B){
        cout<<func(B)-func(A-1ll)<<endl;
    }
}