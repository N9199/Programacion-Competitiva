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
#define pb push_back

int main(){
    int t;
    while(cin>>t){
        int a;
        int n=0;
        rep(i,5){
            cin>>a;
            if(a==t){
                ++n;
            }
        }
        cout<<n<<"\n";
    }
    return 0;
}