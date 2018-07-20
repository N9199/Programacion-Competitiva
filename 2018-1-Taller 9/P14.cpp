#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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
#define debugx(x) cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl

int asdfgbh;

vi primes;
vi numbers;
int n_primes;
void prgen(){
    repx(i,2,asdfgbh){
        if(numbers[i]==0){
            numbers[i] = i;
            ll C = 1ll*i*i;
            while(C <= asdfgbh-1){
                if(numbers[C] == 0)
                    numbers[C]=i;
                C+=i;
            }
            primes.eb(i);
            n_primes++;
        }
    }
}

bool is_prime(int n){
    for(auto p : primes){
        if(n%p == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    asdfgbh = sqrt(n)+1;
    numbers.assign(asdfgbh, 0);
    prgen();
    
    invrep(i, min(n-290,0), n){
        if(is_prime(i)){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}