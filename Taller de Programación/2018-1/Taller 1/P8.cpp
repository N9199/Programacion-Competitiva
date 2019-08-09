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

bool lt(iii &a, iii &b){
    return a.first.first<b.first.second?true:(a.first.first==b.first.first && a.first.second>b.first.second)?true:false;
}

struct Point {
    int x,y;
    ll p;

    bool operator<(const Point& p) const {
        return x<p.x?true:(x==p.x && y>p.y)?true:false;
    }
};
typedef vector<Point > vpoint;


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

    map<par, ll> m;
    set<int> s;

    int b,f,d;
    rep(i,n){
        cin>>b>>f>>d;
        par query(b,f);
        s.insert(f);
        auto it = m.find(query);
        if(it == m.end())
            m[query] = d;
        else
            it->second += d;
    }
    int j = 0;
    umap<int, int> compacter;
    for(auto& q : s)
        compacter[q] = ++j;

    vpoint points(m.size());
    
    FenwickTree ft(j+1);

    int i = 0;
    for(auto& q : m){
        points[i++] = {q.first.first, compacter[q.first.second], q.second};
    }

    sort(points.begin(), points.end());

    for(auto& p : points)
        ft.update(p.y, ft.rmq(p.y-1) + p.p);
    //cout<<"asdf\n";
    //rep(i, temp.size())
        //cout << st.query(i,i) << endl;

    cout<<ft.rmq(j)<< endl;
    return 0;
}