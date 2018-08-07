#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<char> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i,n) for(size_t i = 0; i < (size_t)n; i++)
#define repx(i,a,b) for(size_t i = a; i < (size_t)b; i++)
#define invrep(i,a,b) for(int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugv(v) //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout<<endl

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};
double cross(Point &a, Point &b, Point &c)
{
    double dx0 = b.x - a.x, dy0 = b.y - a.y;
    double dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}
int orientation(Point &a, Point &b, Point &c)
{
    double tmp = cross(a, b, c);
    return tmp < 0 ? -1 : (tmp == 0 ? 0 : 1);
}

struct line
{
    Point A, B;
    line(double x1, double y1, double x2, double y2) : A(x1, y1), B(x2, y2) {}
    bool intersect(line &o)
    {
        int o11 = orientation(A, o.A, o.B);
        int o12 = orientation(B, o.A, o.B);
        int o21 = orientation(A, B, o.A);
        int o22 = orientation(A, B, o.B);

        return (o11 != o12) and (o21 != o22);
    }
    char place(Point &o){
        unordered_map<int, char> m;
        m[-1] = 'D';
        m[0] = 'C';
        m[1] = 'I';
        return m[orientation(A, B, o)];
    }
};

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    line L(x1,y1,x2,y2);
    int q;
    cin>>q;
    int x,y;
    rep(_,q){
        cin>>x>>y;
        Point A(x,y);
        cout<<L.place(A)<<'\n';
    }
    return 0;
}