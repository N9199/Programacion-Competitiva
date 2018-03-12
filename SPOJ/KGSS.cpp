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

class seg_tree{
vp tree;
vi arr;
int n;

    void build(int node, int left, int right){
        if(left == right){
            tree[node] = par(arr[left],0);
        }else{
            int mid = (right + left)/2;
            build(2*node, left, mid);
            build(2*node+1, mid+1, right);
            tree[node] = max(tree[2*node],tree[2*node+1]);//operation
        }
    }

    par query(int node, int start, int end, int l, int r){
        if(r < start or l > end)
            return par(0,0); //Neutro
        if(l <= start and end <= r)
            return tree[node];
        int mid = (start + end)/2;
        par p1 = query(2*node, start, mid, l, r);
        par p2 = query(2*node+1, mid+1, end, l, r);
        //cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
        return max(p1,p2);//operation
    }

    void update(int node, int start, int end, int i, int val){
        if(start == end){
            arr[i] = val;//Update
            tree[node] = par(arr[i],0);//Update
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

    int max(int a, int b){
        return a>b?a:b;
    }

    par max(par a, par b){//Redo
        int c,d;
        if(a.first>b.first)
            c = a.first, d = max(b.first, a.second);
        else
            c = b.first, d = max(a.first, b.second);
        return par(c,d);
    }

public:
    seg_tree(vi& A){
        arr = A;
        n = A.size();
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    int query(int l, int r){
        par temp = query(1, 0 ,n-1, l, r);
        return temp.first+temp.second;
    }

    void update(int i, int value){
        update(1, 0, n-1, i, value);
    }
};

int main(){
    int n,q;
    cin>>n;
    vi v(n);
    rep(i,n)
        cin>>v[i];
    cin>>q;
    seg_tree t(v);

    char d;
    int a,b;
    rep(i,q){
        cin>>d>>a>>b;
        if(d == 'U')
            t.update(a-1,b);
        else if(d == 'Q')
            cout<<t.query(a-1,b-1)<<'\n';
    }
    return 0;
}