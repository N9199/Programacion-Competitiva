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

#define rep(i,n) for(int i = 0; i < n; ++i)
#define repx(i,a,b) for(int i = a; i < b; ++i)
#define invrep(i,a,b) for(int i = b; i >= a; --i)
#define uset unordered_set
#define gcd __gcd
#define eb emplace_back
#define pb push_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout<<endl
#define debugv(v) //cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl
vi den;
int n, k;
uset<int> bills;

int func(int money) {
    int ans = INT_MAX;
    int m_index = distance(den.begin(), lower_bound(den.begin(), den.end(), money));
    if(m_index > den.size())
        return -1;

    if(m_index == den.size())
        m_index--;

    invrep(i, 0, m_index){
        debugx(i);
        int l_max = money/den[i];
        if(money % den[i] == 0){
            if(l_max <= k)
                ans = min(ans, l_max);
            break;
        }else if(l_max + 1 > k)
            break;
        
        invrep(l, 1, l_max){
            debugx(l);
            int resto = money - l * den[i];
            repx(m, 1, k - l +1){
                debugx(m);
                if(resto % m == 0 and bills.find(resto / m) !=  bills.end()){
                    ans = min(ans, l+m);
                    break;
                }
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main(){
    int n; cin >> n >> k;
    den.assign(n, 0);
    rep(i,n){
        cin>>den[i];
        bills.insert(den[i]);
    }

    int q; cin >> q;
    rep(i,q){
        int input; cin >> input;
        cout<<func(input)<<"\n";
    }
}
