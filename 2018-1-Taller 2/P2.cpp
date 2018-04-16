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

vll primes;

void p(ll n){
    vector<bool> is_prime(n + 1, true);
	int limit = (int) floor(sqrt(n));
	repx(i,2,limit+1) 
		if (is_prime[i])
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
    repx(i,2,n) if (is_prime[i]) primes.push_back(i);
}

void print(){
    for(auto p : primes)
        cout<<p<<"\n";
}

bool find(ll n, int l, int r){
    if(l==r)
        return n==primes[l];
    int m = (l+r)/2;
    if(primes[m]<n)
        return find(n, m+1, r);
    else
        return find(n, l, m);
}

int main(){
    int n;
    cin>>n;
    vll nums(n);
    ll maxn = 0;
    rep(i,n){
        cin>>nums[i];
        maxn = max(maxn, nums[i]);
    }
    p(floor(sqrt(maxn))+1ll);
    //cout<<"Hola"<<endl;
    //print();
    rep(i,n){
        if(nums[i] == 1)
            cout<<"NO\n";
        else if(sqrt(nums[i])!=floor(sqrt(nums[i])))
            cout<<"NO\n";
        else if(find(sqrt(nums[i]), 0, primes.size()-1))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}