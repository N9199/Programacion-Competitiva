#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,int> par;
typedef pair<int,ll> ilpar;
typedef vector<par> vp;

#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define gcd __gcd
#define eb emplace_back
#define pb push_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout<<endl
#define debugv(v) //cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))

class Tree{
    vi nodes;
    int size;
    int height;
    void fill(int n, vi &leafs){
        if(lg(n) < height){
            fill(2*n, leafs);
            fill(2*n+1, leafs);
            nodes[n] = operation(nodes[2*n], nodes[2*n+1], (height-lg(n))%2);
        }else{
            nodes[n] = leafs[n-(1<<height)];
        }
    }
    void update(int n, int value){
        nodes[n] = value;
        debugx(n);
        n = n>>1;
        while(n>0){
            debugx(n);
            nodes[n] = operation(nodes[2*n], nodes[2*n+1], (height-lg(n))%2);
            n = n>>1;
        }
    }
    int operation(int a, int b, int type){
        return type ? a | b : a ^ b;
    }
    void debug(int n){
        if(lg(n)>height)
            return;
        cerr<<"Node: "<<n<<" "<<nodes[n]<<"\n";
        debug(2*n);
        debug(2*n+1);
    }
public:
    Tree(ll n, vi leafs){
        this->height = lg(n);
        n = 2*n-1;
        this->size = n;
        nodes.resize(n+1);
        fill(1, leafs);
    }

    void update_leaf(int n, int value){
        update(n+(1<<height), value);
        //debug();
    }

    int value(){
        return nodes[1];
    }
    void debug(){
        cerr<<"Tree:\n";
        cerr<<"Height:"<<height<<"\n";
        debug(1);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    n = 1<<n;
    vi leafs(n);
    rep(i,n)
        cin>>leafs[i];
    //debugx(lg(1));
    Tree t(n, leafs);
    //t.debug();
    int a,b;
    rep(i,m){
        cin>>a>>b;
        --a;
        t.update_leaf(a, b);
        cout<<t.value()<<"\n";
    }

    return 0;
}