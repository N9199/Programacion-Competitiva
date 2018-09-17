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

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) \
    //cerr << #v << ":";                          \
    rep(i, (int)v.size()) cerr << ", " << v[i]; \
    cerr << endl
#define debugm(m) \
    //cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) \
    //cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct cilindre
{
    double x, y;
    cilindre(double x, double y) : x(x), y(y) {}

    cilindre operator*(cilindre &o)
    {
        double dx1 = o.x - x;
        double dy1 = o.y - y;
        double d = sqrt(dx1 * dx1 + dy1 * dy1);
        double alpha = acos(d * 0.25);
        double beta = abs(atan2(dy1, dx1));
        double dx2 = 2 * cos(alpha + beta);
        double dy2 = 2 * sin(alpha + beta);

        if (dy1 >= 0)
            return cilindre(x + dx2, y + dy2);
        else
            return cilindre(o.x - dx2, o.y + dy2);
    }

    friend ostream &operator<<(ostream &strm, const cilindre &a);
};

ostream &operator<<(ostream &strm, const cilindre &a)
{
    return strm << a.x << ' ' << a.y;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    int i = 0;
    while (true)
    {
        scanf("%d", &n);
        vector<vector<cilindre>> l(2);
        if (n == 0)
            return 0;
        double first;
        double last;
        rep(_, n)
        {
            double temp;
            scanf("%lf", &temp);
            l[0].eb(temp, 1.0);
        }
        sort(l[0].begin(), l[0].end(), [](cilindre &a, cilindre &b) {
            return a.x < b.x;
        });
        first = l[0][0].x;
        last = l[0][n - 1].x;
        int c1 = 0;
        int c2 = 1;
        while (--n)
        {
            l[c2].clear();
            rep(i, n)
            {
                l[c2].eb(l[c1][i] * l[c1][i + 1]);
            }
            l[c1].clear();
            swap(c1, c2);
        }
        l[c1][0].x = ((last + first) * 0.5 + l[c1][0].x) * 0.5;
        //cout << ++i << ": " << l[c1][0] << '\n';
        printf("%.4lf %.4lf\n", l[c1][0].x, l[c1][0].y);
    }
    return 0;
}
