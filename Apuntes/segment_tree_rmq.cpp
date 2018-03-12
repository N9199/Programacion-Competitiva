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
vi tree, arr;
int n;

    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
        }else{
            int mid = (right + left)/2;
            build(2*node, left, mid);
            build(2*node+1, mid+1, right);
            tree[node] = min(tree[2*node],tree[2*node+1]);//operation
        }
    }

    int query(int node, int start, int end, int l, int r){
        if(r < start or l > end)
            return 1e9; //Neutro
        if(l <= start and end <= r)
            return tree[node];
        int mid = (start + end)/2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return min(p1,p2);//operation
    }

    void update(int node, int start, int end, int i, int val){
        if(start == end){
            arr[i] += val;
            tree[node];
        }else{
            int mid = (start + end)/2;
            if(start <= i and i <= mid){
                update(2*node, start, mid, i, val);
            }else{
                update(2*node+1, mid+1, end, i, val);
            }
            tree[node] = min(tree[2*node],tree[2*node+1]);//operation
        }
    }

public:
    seg_tree(vi& A){
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
    vi a(n);
    rep(i,n)
        cin>>a[i];
    seg_tree s(a);

    cout<<"min[0,"<<n-1<<"]="<<s.query(0,n-1);
    cout<<" ";
    cout<<"min[0,4]="<<s.query(0,4);
    cout<<" ";
    cout<<"min[2,4]="<<s.query(2, 4);
    cout<<endl;

    return 0;
}