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
typedef vector<Point > viii;

class seg_tree{
vll tree, arr;
int n;

    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
        }else{
            int mid = (right + left)/2;
            build(2*node, left, mid);
            build(2*node+1, mid+1, right);
            tree[node] = max(tree[2*node],tree[2*node+1]);//operation
        }
    }

    ll query(int node, int start, int end, int l, int r){
        if(r < start or l > end)
            return 0; //Neutro
        if(l <= start and end <= r)
            return tree[node];
        int mid = (start + end)/2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return max(p1,p2);//operation
    }

    void update(int node, int start, int end, int i, ll val){
        if(start == end){
            arr[i] = val;
            tree[node] = arr[i];
        }else{
            int mid = (start + end)/2;
            if(start <= i and i <= mid){
                update(2*node, start, mid, i, val);
            }else{
                update(2*node+1, mid+1, end, i, val);
            }
            tree[node] = max(tree[2*node],tree[2*node+1]);//operation
        }
    }

public:
    seg_tree(vll& A){
        arr = A;
        n = A.size();
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    int query(int l, int r){
        return query(1, 0 ,n-1, l, r);
    }

    void update(int i, int value){
        update(1, 0, n-1, i, value);
    }
};


int main(){
    int n;
    cin>>n;
    int a,b,c;
    map<par, int> v;
    //unordered_set<par> asdf;
    rep(i,n){
        cin>>a>>b>>c;
        par query(a,b);
        auto it = v.find(query);
        if(it == v.end())
            v[query] = c;
        else
            it->second += c;
    }
    viii E(v.size()+1);
    vi f(v.size()+1);
    set<int> e;
    E[0] = {-1, -1, 0};

    int asdfghjk = 1;
    for(auto q : v){
        E[asdfghjk++] = {q.first.first, q.first.second, q.second}; 
        e.insert(q.first.second);
    }
    sort(E.begin(),E.end());
    int asdfgh = 0;
    for(auto it = e.begin(); it!=e.end(); ++it)
        asdfgh = max(asdfgh, *it);
    vll m(asdfgh+1,0);
    seg_tree st(m);
    
    //for(auto q : E)
    //    cout<<q.x<<" "<<q.y<<" "<<q.p<<endl;
    
    repx(i,1,f.size()){
        f[i] = st.query(1,E[i].y-1) + E[i].p;
        st.update(E[i].y, f[i]);
    }

    //for(auto g : v)
    //    cout<< g.first.first << " " << g.first.second << " " << g.second << "\n";
    cout << st.query(1, asdfgh) << endl;
    //rep(i, asdfgh+1)
    //    cout << st.query(i,i) <<endl;
    
    return 0;
}