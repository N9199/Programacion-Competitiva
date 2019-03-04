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

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  //cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}

    friend ostream &operator<<(ostream &strm, const Point &a);
};

ostream &operator<<(ostream &strm, const Point &a)
{
    return strm << '(' << a.x << ',' << a.y << ')';
}

double cross(Point &a, Point &b, Point &c)
{
    double dx0 = b.x - a.x, dy0 = b.y - a.y;
    double dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}

struct line
{
    Point A, B;
    line(double x1, double y1, double x2, double y2) : A(x1, y1), B(x2, y2) {}
    line(Point A, Point B) : A(A), B(B) {}
    bool intersect(line &o)
    {
        int o11 = orientation(A, o.A, o.B);
        int o12 = orientation(B, o.A, o.B);
        int o21 = orientation(A, B, o.A);
        int o22 = orientation(A, B, o.B);

        return (o11 != o12) and (o21 != o22);
    }

    int orientation(Point &a, Point &b, Point &c)
    {
        double tmp = cross(a, b, c);
        return tmp < 0 ? -1 : (tmp == 0 ? 0 : 1);
    }

    int orientation(Point &a)
    {
        return orientation(A, B, a);
    }

    friend ostream &operator<<(ostream &strm, const line &a);
};

ostream &operator<<(ostream &strm, const line &a)
{
    return strm << a.A << ' ' << a.B;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<Point> vp;
    vector<line> vl;
    rep(_, n)
    {
        int x, y;
        cin >> x >> y;
        vp.eb(x, y);
    }
    rep(i, n)
        vl.eb(vp[i], vp[(i + 1) % n]);

    rep(_, q)
    {
        int x, y;
        cin >> x >> y;
        Point A(x, y);
        int p = vl[0].orientation(A);
        int c;
        bool flag = true;
        debugx(p);
        rep(i, 2*n)
        {
            int c = vl[i%n].orientation(A);
            debugx(c);
            if (c != p and c!=0 and p!=0)
            {
                cout<<"F\n";
                flag = not flag;
                break;
            }
            int p = c;
        }
        if (flag)
            cout<<"D\n";
    }
    return 0;
}