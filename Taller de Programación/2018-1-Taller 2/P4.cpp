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

int main(){
    int n;
    string t; 
    cin>>n>>t;
    string a;
    if(t=="10" and n==1){
        cout<<-1<<endl;
        return 0;
    }else if(t=="10"){
        --n;
        a+="1";
        t="0";
    }
    rep(i,n)
        a+=t;
    cout<<a<<endl;
    return 0;
}