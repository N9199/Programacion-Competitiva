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

struct segment{
    int l,r,c;

    bool operator<(const segment& s) const{
        return l<s.l;
    }
};

int main(){
    int l,c,n;
    cin>>l>>c>>n;
    set<segment> segments;
    segments.insert({0,l-1,1});
    int m1,m2;
    int p,x,a,b;
    int s;
    rep(i,n){
        segment temp;
        cin>>p>>x>>a>>b;
        s=0;
        for(auto& seg:segments)
            s += seg.c==p?seg.r-seg.l+1:0;
        m1 = (a+(s*s%l))%l;
        m2 = (a+(((s+b)%l)*((s+b)%l)%l))%l;
        a = min(m1,m2);
        b = max(m1,m2);
        int flag = 0;
        set<segment> temp;
        for(auto it=segments.begin(); it!=segments.end();++it){
            if(flag==0){
                
            }else if(flag==1){

            }else{

            }
        }
    }
    vi col(c);
    for(auto& seg:segments)
        col[seg.c-1]+=seg.r-seg.l+1;
    int ans = 0;
    for(auto& num: col)
        ans = max(ans, num);
    cout<<ans<<endl;
    return 0;
}