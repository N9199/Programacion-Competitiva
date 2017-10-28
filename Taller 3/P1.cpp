#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long intt;
typedef pair<int, int> par;
typedef vector<vector<int> > graph;
                                                
typedef vector<vector<par> > wgraph;   


#define rep(i,n) for(int i=0; i<(int)n;++i)
// Example of SegmentTree for rmq (range minimum query)
// Note: instead of storing the minimum value, each node will store 
//  the index of the leftmost position of the range in which the minimum
//  value of that range is found

struct prodsgn {
    int sgn;
    prodsgn() {sgn = 1;}
    prodsgn(int x) {
        sgn = (x > 0) - (x < 0);
    }
    prodsgn(const prodsgn &a,
            const prodsgn &b) {
        sgn = a.sgn*b.sgn;
    }
};


template<class node> class ST {
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr) {
        n = arr.size();
        t.resize(n*2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n-1; i > 0; --i)
            t[i] = node(t[i<<1], t[i<<1|1]);
    }

    // 0-indexed
    void set_point(int p, const node &value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p>>1] = node(t[p], t[p^1]);
    }

    // inclusive exclusive, 0-indexed
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ansl = node(ansl, t[l++]);
            if (r&1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

  
// usage
int main() {
    int n,k;
    while(cin>>n>>k){
        vi arr(n);
        rep(i,n){
            cin>>arr[i];
        }
        ST<prodsgn> st(arr);
        rep(i,k){
            char a;
            cin>>a;
            int b,c;
            if(a=='C'){
                cin>>b>>c;
                st.set_point(b-1,prodsgn(c));
            }else if(a=='P'){
                cin>>b>>c;
                int d=st.query(b-1,c-1);
                cout<<d<<endl;
                if(d<0){
                    cout<<'-';
                }else if(d>0){
                    cout<<'+';
                }else{
                    cout<<'0';
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}