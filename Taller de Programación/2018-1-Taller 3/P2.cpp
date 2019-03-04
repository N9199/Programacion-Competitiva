#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef pair<par, int> iii;
typedef vector<int > vi;
typedef vector<char > vc;
typedef vector<string > vs;
typedef vector<ll > vll;
typedef vector<par > vp;
typedef vector<vi > graph;

typedef vector<vp > wgraph;

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define invrep(i,n) for(int i=n;i--;)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

int main(){
    int p=0,n=0;
    string s;
    cin>>s;
    for(auto c : s){
        if(c=='+')
            p++;
        if(c=='-')
            n++;
    }
    int p2=0,n2=0;
    cin>>s;
    for(auto c : s){
        if(c=='+')
            p2++;
        if(c=='-')
            n2++;
    }
    int q = n+p-n2-p2;
    double a;
    return 0;
}