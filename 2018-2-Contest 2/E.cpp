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
#define debugv(v) \
    // cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
    cerr << endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

double mid;

struct pol
{
    vi cofs;
    pol(vi cofs) : cofs(cofs) {}

    double operator()(double x)
    {
        double x_0 = 1;
        double ans = 0;
        for (auto cof : cofs)
        {
            ans += x_0 * cof;
            x_0 *= x;
            if (x_0 == 0)
                break;
        }
        return ans;
    }
};

struct rat
{
    pol p, q;
    rat(pol p, pol q) : p(p), q(q) {}

    double operator()(double x)
    {
        return max(-mid, p(x) / q(x));
    }
};

double integrate(function<double(double)> f, double a, double b)
{
    double c = (a + b) / 2;
    double h3 = abs(b - a) / 6;
    return h3 * (f(a) + 4 * f(c) + f(b));
}

double integrate(function<double(double)> f, double a, double b, double eps)
{
    int n = (b - a) / eps;
    n /= 100;
    debugx(n);
    double dx = (b - a) / n;
    double ans = 0;
    double h = 0;
    rep(_, n)
    {
        ans += integrate(f, h, h + dx);
        h += dx;
    }
    return ans;
}

main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(5);
    int w, d, a, k;
    while (cin >> w >> d >> a >> k)
    {
        k++;
        vi temp(k);
        debugx(k);
        rep(i, k)
        {
            cin >> temp[i];
        }
        debugv(temp);

        pol p(temp);

        rep(i, k)
        {
            cin >> temp[i];
        }
        debugv(temp);

        pol q(temp);

        rat y1(p, q);

        rep(i, k)
        {
            cin >> temp[i];
        }
        debugv(temp);

        p.cofs = temp;

        rep(i, k)
        {
            cin >> temp[i];
        }
        debugv(temp);

        q.cofs = temp;

        rat y2(p, q);

        double eps = 1e-5;
        int n = log(1 / eps);
        n += 60;
        debugx(n);
        double right = d;
        double left = 0;
        rep(_, n)
        {
            mid = (right + left) / 2;
            double a1 = integrate(y1, 0, w, eps);
            double a2 = integrate(y2, 0, w, eps);
            if (a1 - a2 > a)
                right = mid;
            else
                left = mid;
        }
        cout << (right + left) / 2 << '\n';
    }
    return 0;
}
