#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> par;
typedef tuple<ll, ll, ll> iii;
typedef vector<int > vi;
typedef vector<string > vs;
typedef vector<par > vp;
typedef vector<vi > graph;

typedef vector<vp > wgraph;

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

const ll MOD = 0x3b9aca07;
const int N_STATES = 1 << 16;

vector<string> seq;
ll sums[N_STATES];

int char2idx(char c) {
    if ('0' <= c and c <= '9') return c - '0';
    return 10 + (c - 'a');
}

ll string2hex(string& s, int mask) {
    ll hex = 0;
    for (char c: s) {
        int x = char2idx(c);
        if (((mask >> x) & 1) == 0) {
            hex = (hex << 4) + x;
        }
    }
    return hex;
}

ll minsums[N_STATES];
ll min_path_sum(int mask) {
    if (mask == 0) return 0;
    if (minsums[mask] < LLONG_MAX) return minsums[mask];
    for (int i = 0, b=1; i < 16; i++, b<<=1) {
        if (mask & b) {
            minsums[mask] = min(minsums[mask], min_path_sum(mask & (~b)));
        }
    }
    minsums[mask] += sums[mask];
    return minsums[mask];
}

ll maxsums[N_STATES];
ll max_path_sum(int mask) {
    if (mask == 0) return 0;
    if (maxsums[mask] > -1) return maxsums[mask];
    for (int i = 0, b=1; i < 16; i++, b<<=1) {
        if (mask & b) {
            maxsums[mask] = max(maxsums[mask], max_path_sum(mask & (~b)));
        }
    }
    maxsums[mask] += sums[mask];
    return maxsums[mask];
}

ll inline mod_mult(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll inline mod_sum(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}


int main(){
    int n;
    cin>>n;
    seq.resize(n);
    rep(i,n)
        cin>>seq[i];

    ll fact[20];
    fact[0] = 1;
    for(ll i = 1; i < 21; i++) fact[i] = mod_mult(fact[i-1], i);

    ll totsum = 0;
    repx(mask, 1, 0xffff){
        ll sum = 0;
        for(string& s: seq) sum += string2hex(s, mask);
        sums[mask] = sum;
        int x = __builtin_popcount(mask);
        totsum = mod_sum(totsum, mod_mult(sum, mod_mult(fact[x], fact[16-x])));
    }

    rep(i,N_STATES) maxsums[i] = -1;
    rep(i,N_STATES) minsums[i] = LLONG_MAX;
    ll minsum = min_path_sum(0xffff);
    ll maxsum = max_path_sum(0xffff);

    printf("%llx %llx %llx\n", minsum, maxsum, totsum);

    return 0;
}