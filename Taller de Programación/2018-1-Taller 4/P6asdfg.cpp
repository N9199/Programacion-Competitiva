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

unordered_map<char, int> m;
unordered_map<int, char> m1;
vll pow15(10);
graph dp(20, vi(20, -1));

int func(int n, int k){
    if(n == k or k == 0 or n == 0)
        return 1;
    if(dp[n][k] != -1)
        return dp[n][k];
    return dp[n][k] = func(n-1, k) + func(n-1, k-1);
}

int BitCount(int u)                          {
    uint uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

ll hexToInt(vs s){
    ll out = 0;
    for(auto& str : s){
        rep(i, str.size()){
            out += pow15[i]*m[str.at(str.size()-i-1)];
        }
    }
    return out;
}

unordered_set<int> ids;

class Node;

Node create(vs values, int i, int j);
vector<Node> nodes;

class Node{
private:
    vs values;
    int hex_list;
    ll Min = -1;
    ll Max = -1;
    ll Sum = -1;
    vi child_nodes;
public:
    Node(){
        hex_list = -1;
    }
    Node(vs vals, int i){
        ids.insert(i);
        values = vals;
        hex_list = i;
        int c = (1<<16)-1;
        if((i&c) != c){
            rep(j, 16){
                if((i|(1<<j)) == i) continue;
                if(nodes[i|(1<<j)].hex_list == -1){
                    nodes[i|(1<<j)] = create(vals, i, j);
                }
                child_nodes.pb(i|(1<<j));
            }
        }
    }
    iii query(){
        cout<<"ID: "<<hex_list<<endl;
        cout<<"BEGIN: "<<Min<<" "<<Max<<" "<<Sum<<endl;
        if(Min != -1 and Max != -1 and Sum != -1)
            return iii(Min, Max, Sum);
        if(hex_list == (1<<16)-1)
            return iii(0, 0, 0);
        ll tempmin = (ll)1e11;
        ll tempmax = 0;
        ll tempsum = 0;
        for(auto index : child_nodes){
            iii temp = nodes[index].query();
            tempmin = min(tempmin, get<0>(temp));
            tempmax = max(tempmax, get<1>(temp));
            tempsum = (tempsum + get<2>(temp))%((ll)1e9+7);
        }
        if(hex_list != 0){
            Min = tempmin + hexToInt(values);
            Max = tempmax + hexToInt(values);
            Sum = (tempsum + (func(16, BitCount(hex_list))*hexToInt(values))%((ll)1e9+7))%((ll)1e9+7);
        }else{
            Min = tempmin;
            Max = tempmax;
            Sum = tempsum;
        }
        cout<<"END: "<<Min<<" "<<Max<<" "<<Sum<<endl;
        return iii(Min, Max, Sum);
    }
};

Node create(vs values, int i, int j){
    vs vals;
    char e = m1[j];
    for(auto &s : values){
        s.erase(std::remove(s.begin(), s.end(), e), s.end());
        vals.pb(s);
    }
    return Node(vals, i|(1<<j));
}

int main(){
    nodes.resize(((int)7e4));
    pow15[0] = 1;
    repx(i,1, pow15.size())
        pow15[i] = (pow15[i-1]*15);
    rep(i,10){
        m['0'+i] = i;
        m1[i] = '0' + i;
        //cout<<(char)('0'+i)<<endl;
    }
    rep(i,6){
        m['a'+i] = i + 10;
        m1[i+10] = 'a' + i;
        //cout<<(char)('a'+i)<<endl;
    }
    int n;
    cin>>n;
    vs values(n);
    rep(i,n)
        cin>>values[i];
    for(auto& value : values)
        cout<<value<<endl;
    Node N(values, 0);
    iii out = N.query();
    cout<<hex<<get<0>(out)<<" "<<get<1>(out)<<" "<<get<2>(out)<<endl;
    return 0;
}