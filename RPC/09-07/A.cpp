#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; ++i)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << _p.first << ' ' << _p.second;
    return _os;
}

const double R = 6371;
const double PI = 3.14159265358979323846;

struct point
{
    double x, y, z;
    point(double x, double y, double z) : x(x), y(y), z(z) {}
    point(double theta, double phi) : x(cos(phi) * cos(theta)), y(cos(phi) * sin(theta)), z(sin(phi)) {}
    point operator*(double t)
    {
        return {t * x, t * y, t * z};
    }
    point operator+(const point &a)
    {
        return {x + a.x, y + a.y, z + a.z};
    }
    point operator-(const point &a)
    {
        return {x - a.x, y - a.y, z - a.z};
    }
    double norm()
    {
        return sqrt(x * x + y * y + z * z);
    }
    double dist(const point &o)
    {
        return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y) + (z - o.z) * (z - o.z));
    }
};

struct line
{
    point a, b;
    point operator()(double t)
    {
        point temp = a * (1 - t) + b * t;
        return temp * (1 / temp.norm());
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(6);
    int n;
    cin >> n;
    rep(_, n)
    {
        double phi1, theta1, phi2, theta2;
        cin >> phi1 >> theta1 >> phi2 >> theta2;
        phi1 *= PI / 180.0;
        theta1 *= PI / 180.0;
        phi2 *= PI / 180.0;
        theta2 *= PI / 180.0;
        debugx(make_pair(phi1, theta1));
        debugx(make_pair(phi2, theta2));
        line route = {point(theta1, phi1), point(theta2, phi2)};
        double start = 0;
        cerr << route.a.x << " " << route.a.y << " " << route.a.z << ", " << route.b.x << " " << route.b.y << " " << route.b.z << endl;
        double end = 1;
        point north(PI / 2, 0);
        rep(__, 80)
        {
            double left = start + (end - start) / 3;
            double right = start + ((end - start) * 2) / 3;
            if (route(left).dist(north) < route(right).dist(north))
            {
                end = right;
            }
            else
            {
                start = left;
            }
        }
        if (route((start + end) / 2).dist(north) < min(route(start).dist(north), route(end).dist(north)))
        {
            cout << "Alex\n"
                 << route((start + end) / 2).dist(north)*R << "\n\n";
        }
        else
        {
            cout << "Timothy\n"
                 << min(route(start).dist(north), route(end).dist(north))*R << "\n\n";
        }
    }
}