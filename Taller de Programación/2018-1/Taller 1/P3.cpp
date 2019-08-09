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
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    rep(i,n-1){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<"\n";
    return 0;
}