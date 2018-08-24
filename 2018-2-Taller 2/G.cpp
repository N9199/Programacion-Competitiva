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

const double PI = acos(-1);

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

struct squared
{
    function<double(double)> f;
    squared(function<double(double)> f) : f(f) {}
    double operator()(double x)
    {
        return f(x) * f(x);
    }
};

double
integrate(function<double(double)> f, double a, double b)
{
    double c = (a + b) / 2;
    double h3 = abs(b - a) / 6;
    return h3 * (f(a) + 4 * f(c) + f(b));
}

double integrate(function<double(double)> f, double a, double b, double eps)
{
    double temp = log((b - a) / eps);
    temp = temp > 0 ? temp : 10;
    int n = temp * 10;
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(2);

    int n;
    int ncase = 0;
    while (cin >> n)
    {
        ncase++;
        n++;
        vi temp(n);
        rep(i, n)
        {
            cin >> temp[i];
        }
        pol p(temp);
        squared f(p);
        double x_low, x_high;
        int mark;
        cin >> x_low >> x_high >> mark;
        double total = integrate(f, x_low, x_high, 1e-2);
        cout << "Case " << ncase << ": " << 2*PI*total << '\n';
    }

    return 0;
}
