#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef pair<par, int> iii;
typedef vector<int > vi;
typedef vector<ll > vll;
typedef vector<par > vp;
typedef vector<vi > graph;

typedef vector<vp > wgraph;

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

vi dp(4001, -1);
vi n(3);
int f(int i){
    if(i == 0)
        return 0; 
    if(dp[i]!=-1)
        return dp[i];
    int m = -1e9;
    for(auto p : n)
        if(i-p>=0) m = max(m, f(i-p));

    return dp[i]=m+1;
}


int main(){
    int m;
    cin>>m;
    rep(i,3)
        cin>>n[i];
    cout<<f(m)<<endl;
    return 0;
}