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
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    vi temp;
    for(auto c : s){
        if(c=='B')
            temp.pb(0);
        else
            temp.pb(1);
    }
    rep(i,t){
        rep(j,n-1){
            if(temp[j]==0 && temp[j+1]==1){
                //cout << j <<" Hola\n";
                temp[j] = 1;
                temp[++j] = 0;
            }
        }
    }
    string str;
    for(auto n : temp){
        if(n==1)
            str.pb('G');
        else
            str.pb('B');
    }
    cout<<str<<"\n";
    return 0;
}