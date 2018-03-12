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

#define int long long

int mulmod(uint a, uint b, uint p)
{
    int x = 0, y = a % p;
    while (b) {
        if (b & 1) x = (x + y) % p;
        y = (y << 1) % p;
        b >>= 1;
    }
    return x % p;
}


int fastPow(int x, int n, int MOD)
{
    int ret = 1;
    while (n) {
        if (n & 1) ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret;
}

class seg_tree{
vi tree, arr;
int n, p, b;

    void build(int node, int left, int right){
        if(left == right){
            tree[node] = mulmod(arr[left],fastPow(b, n-left-1, p), p);
        }else{
            int mid = (right + left)/2;
            build(2*node, left, mid);
            build(2*node+1, mid+1, right);
            tree[node] = (tree[2*node]+tree[2*node+1])%p;//operation
        }
    }

    int query(int node, int start, int end, int l, int r){
        if(r < start or l > end)
            return 0; //Neutro
        if(l <= start and end <= r)
            return tree[node];
        int mid = (start + end)/2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return (p1+p2)%p;
    }

    void update(int node, int start, int end, int i, int val){
        if(start == end){
            //cout<<start<<endl;
            arr[i] = val;
            tree[node] = mulmod(arr[i],fastPow(b, n-i-1, p), p);            
        }else{
            int mid = (start + end)/2;
            if(start <= i and i <= mid){
                update(2*node, start, mid, i, val);
            }else{
                update(2*node+1, mid+1, end, i, val);
            }
            tree[node] = (tree[2*node]+tree[2*node+1])%p;//operation
        }
    }

public:
    seg_tree(vi& A, int pr, int br){
        p = pr;
        b = br;
        arr = A;
        n = A.size();
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    int query(int l, int r){
        //cout<<"query"<<endl;
        return query(1, 0 ,n-1, l, r);
    }

    void update(int i, int value){
        //cout<<"update"<<endl;
        update(1, 0, n-1, i, value);
    }
};

#undef int
int main(){
    #define int long long
    int b,p,l,n;
    while(cin>>b>>p>>l>>n){
        if(!(b && p && l && n))
            return 0;
        vi v(l);
        seg_tree t(v, p, b);
        char c;
        int j,a;
        rep(i,n){
            cin>>c>>j>>a;
            if(c == 'E')
                t.update(j-1,a);
            else if(c == 'H')
                cout<<t.query(j-1,a-1)<<'\n';
        }
        cout<<"-\n";
    }
    return 0;
}