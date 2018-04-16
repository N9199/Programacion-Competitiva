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
    int v;
    cin>>v;
    vi l(9);
    rep(i,9)
        cin>>l[i];
    int d = 100001;
    rep(i,9){
        if (l[i]<=d)
            d = l[i];
}
    int p = v/d;

    if (p == 0){
        cout<<-1<<endl;
        return 0;
    }
    int g = v - d*p;
    rep(h,9)
        l[h] -= d;
    vi resp;
    rep(j, p){
        if (l[8] <= g){
            resp.pb(9);
            g -= l[8];
        }
        else if (l[7] <= g){
            resp.pb(8);
            g -= l[7];
        }
        else if (l[6] <= g){
            resp.pb(7);
            g -= l[6];
        }
        else if (l[5] <= g){
            resp.pb(6);
            g -= l[5];
        }
        else if (l[4] <= g){
            resp.pb(5);
            g -= l[4];
        }
        else if (l[3] <= g){
            resp.pb(4);
            g -= l[3];
        }
        else if (l[2] <= g){
            resp.pb(3);
            g -= l[2];
        }
        else if (l[1] <= g){
            resp.pb(2);
            g -= l[1];
        }
        else if (l[0] <= g){
            resp.pb(1);
            g -= l[0];
        }    
    }
    for(auto &n : resp)
        cout<<n;
    cout<<endl;
    return 0;
}