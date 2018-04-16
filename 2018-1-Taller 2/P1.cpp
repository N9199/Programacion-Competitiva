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

void print(vector<vector<char>>& v){
    rep(i,v.size()){
        rep(j,v[i].size())
            cout<<v[i][j];
        cout<<"\n";
    }
}

int main(){
    int n; 
    cin>>n;
    vector<vector<char>> v;
    vector<char> temp(5);
    rep(i,n){
        rep(j, 5)
            cin>>temp[j];
        v.pb(temp);
    }
    char a;
    rep(i,n)rep(j,5)
        if(j == 0){
            a = v[i][0];
            continue;
        }else if(a == v[i][j] && a == 'O'){
            v[i][j] = '+';
            v[i][j-1] = '+';
            cout<<"YES\n";
            print(v);
            return 0;
        }else{
            a = v[i][j];
        }
        cout<<"NO";
    return 0;
}