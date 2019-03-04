#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef pair<par, int> iii;
typedef vector<int > vi;
typedef vector<char > vc;
typedef vector<string > vs;
typedef vector<ll > vll;
typedef vector<par > vp;
typedef vector<vi > graph;

typedef vector<vp > wgraph;

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define invrep(i,n) for(int i=n;i--;)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

graph dp(1e6, vi());
vi d(9);

vi max(vi& a, vi& b){
    rep(i,10){
        if(a[i]>b[i])
            return a;
        if(b[i]>a[i])
            return b;
    }
    return a;
}

vi func(int i, int n){
    //cout<<"i: "<<i<<endl;
    if(i < 0)
        return vi(10, INT_MIN);
    if(i == 0)
        return vi(10, 0);
    //cout<<"Hola"<<endl;
    if(dp[i].size()!=0)
        return dp[i];
    vi lmax = vi(10, 0);
    invrep(j,n){
        //cout<<"j: "<<j+1<<endl;
        //cout<<"i - d[j]: "<<i - d[j]<<endl;
        if(i-d[j]>=0){
            vi temp = func(i - d[j], j+1);
            /*cout<<"1: ";
            rep(i,10)
                cout<<temp[i];
            cout<<endl;*/
            temp[9-j]++;
            temp[0]++;
            /*cout<<"2: ";
            rep(i,10)
                cout<<temp[i];
            cout<<endl;*/
            lmax = max(lmax, temp);
            /*cout<<"lmax: ";
            rep(i,10)
                cout<<lmax[i];
            cout<<endl;*/
        }
    }
    return dp[i]=lmax;
}

int main(){
    int v;
    cin>>v;
    rep(i,9)
        cin>>d[i];

    vi temp = func(v, 9);
    if(temp[0] == 0 or temp[0] == -1){
        cout<<-1<<endl;
        return 0;
    }
    repx(i,1,10)
        while(0 < temp[i]--)
            cout<<10-i;

    cout<<endl;

    return 0;
}