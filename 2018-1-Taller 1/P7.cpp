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
    int a1,b1,c1;
    int a2,b2,c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cout<<max(0,a2-a1)+max(0,b2-b1)+max(0,c2-c1)<<"\n";
    return 0;
}