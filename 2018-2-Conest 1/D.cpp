#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}

    friend ostream &operator<<(ostream &strm, const Point &a);

    Point operator+(const Point &o) { return Point(x + o.x, y + o.y); }
    Point operator-(const Point &o) { return Point(x - o.x, y - o.y); }
    Point operator*(double o) const { return Point(x * o, y * o); }

    double dist(const Point &a)
    {
        return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
    }

    double dot(const Point &a)
    {
        return (x * a.x + y * a.y);
    }
};

ostream &operator<<(ostream &strm, const Point &a)
{
    return strm << '(' << a.x << ',' << a.y << ')';
}

double Q_rsqrt(double number)
{
    long i;
    double x2, y;
    const double threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *)&y;                   // evil floating point bit level hacking
    i = 0x5fe6eb50c7b537a9 - (i >> 1); // what the fuck? x64 constant
    y = *(double *)&i;
    y = y * (threehalfs - (x2 * y * y)); // 1st iteration
    y = y * (threehalfs - (x2 * y * y)); // 2nd iteration, this can be removed

    return y;
}

struct line
{
    Point A, B;
    line(double x1, double y1, double x2, double y2) : A(x1, y1), B(x2, y2) {}
    line(Point A, Point B) : A(A), B(B) {}

    friend ostream &operator<<(ostream &strm, const line &a);

    double dist(Point &o)
    {
        // Return minimum distance between line segment vw and point p
        const double l2 = A.dist(B); // i.e. |w-v|^2 -  avoid a sqrt
        if (l2 == 0.0)
            return A.dist(o); // v == w case
        // Consider the line extending the segment, parameterized as v + t (w - v).
        // We find projection of point p onto the line.
        // It falls where t = [(p-v) . (w-v)] / |w-v|^2
        // We clamp t from [0,1] to handle points outside the segment vw.
        double t = max(0.0, min(1.0, (o - A).dot(B - A) / l2));
        const Point projection = A + (B - A) * t; // Projection falls on the segment
        return o.dist(projection);
    }
};

ostream &operator<<(ostream &strm, const line &a)
{
    return strm << a.A << ' ' << a.B;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    int n;
    cin >> n;
    while (n)
    {
        vector<Point> vp;
        vector<line> vl;
        int x, y;
        cin >> x >> y;
        Point A(x, y);
        rep(_, n)
        {
            cin >> x >> y;
            vp.eb(x, y);
        }
        rep(i, n)
            vl.eb(vp[i], vp[(i + 1) % n]);
        double dist1 = vp[0].dist(A);
        double dist2 = vl[0].dist(A);
        rep(i, n)
            dist1 = min(dist1, vp[i].dist(A));

        rep(i, n)
            dist2 = min(dist2, vl[i].dist(A));

        cout << sqrt(min(dist1, dist2)) << '\n';
        cin >> n;
    }
    return 0;
}