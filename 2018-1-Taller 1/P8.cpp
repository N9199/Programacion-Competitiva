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

    ll query(int l, int r){
        return query(1, 0 ,n-1, l, r);
    }

    void update(int i, int value){
        update(1, 0, n-1, i, value);
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

    vpoint points(m.size()+1);
    vll F(m.size()+1,0);
    points[0] = {-1,-1,0};
    
    vll temp(j+1, 0);
    seg_tree st(temp);

    j = 1;
    for(auto& q : m){
        points[j++] = {q.first.first, compacter[q.first.second], q.second};
    }

    sort(points.begin(), points.end());

    repx(i,1,F.size()) {
        F[i] = st.query(1, points[i].y-1) + points[i].p;
        st.update(points[i].y, F[i]);
        //cout<<points[i].y<<" A "<<st.query(points[i].y, points[i].y)<<" F: "<<F[i]<<endl;
    }
    //cout<<"asdf\n";
    //rep(i, temp.size())
        //cout << st.query(i,i) << endl;

    cout<<st.query(1, temp.size())<< endl;
    return 0;
}