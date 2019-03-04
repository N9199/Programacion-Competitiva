#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<char> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  //cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct Plant{
    int x,y,v;
    Plant(int x, int y, int v): x(x), y(y), v(v) {}
};

struct Fence{
    int x1, y1, x2, y2;
    Fence(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
};


int main(){
    int p,v;
    cin>>p>>v;
    vector<Plant> Plants;


    return 0;
}