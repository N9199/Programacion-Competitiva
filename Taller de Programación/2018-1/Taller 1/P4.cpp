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
    string s;
    int x = 0;
    rep(i,n){
        cin>>s;
        if(s=="--X" or s=="X--"){
            x--;
        }else{
            x++;
        }
    }
    cout<<x<<endl;
    return 0;
}