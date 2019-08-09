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
#define umap unordered_map



struct FenwickTree {
    vector<ll> ft;
    FenwickTree(int n) {
        ft.assign(n+1,0);
    }
    ll rmq(int b) {
        ll ans = 0;
        for (; b; b -= (b & -b)) ans = max(ans, ft[b]);
        return ans;
    }
    void update(int b, ll new_val) {
        for(; b < ft.size(); b += (b & -b)) ft[b] = max(ft[b], new_val);
    }
};

int main(){
    int n;
    cin>>n;
    set<int> s;
    vll v;
    int h,r;
    rep(i,n){
        cin>>r>>h;
        v.pb(r^2*h);
        s.insert(r^2*h);
    }
    int j = 0;
    umap<int, int> compacter;
    for(auto& q : s)
        compacter[q] = ++j;
    
    FenwickTree ft(j+1);

    rep(i,v.size())
        ft.update(i, ft.rmq(i-1) + v[i]);
    //cout<<"asdf\n";
    //rep(i, temp.size())
        //cout << st.query(i,i) << endl;

    cout<<ft.rmq(j)<< endl;
    return 0;
}