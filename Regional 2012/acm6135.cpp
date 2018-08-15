#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<double> vd;
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
#define debugv(v)  cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

double mid;

struct pol{
    vi cof;
    pol(vi cof) : cof(cof) {}

    double operator()(double x){
        double ans = 0;
        double x_i = 1;
        for (int c : cof)
        {
            ans += c * x_i;
            x_i *= x;
        }
        return ans;
    }
};

struct rat{
    pol p,q;
    rat(pol p, pol q): p(p), q(q) {}

    double operator()(double x){
        double ans = p(x)/q(x);
        return max(ans, -mid);
    }
};


double simpsons_rule(function<double(double)> f, double a, double b)
{
    double c = (a + b) / 2;
    double h3 = abs(b - a) / 6;
    double answer = h3 * (f(a) + 4 * f(c) + f(b));
    return answer;
}

double simpsons_rule(function<double(double)> f, double a, double b, int n)
{
    double ans = 0;
    double step = 0, h = (b-a)/n;
    rep(i, n)
    {
        ans += simpsons_rule(f, step, step + h);
        step += h;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(5);
    int w, d, a, k;
    while (cin >> w >> d >> a >> k)
    {
        k++;
        vi l(k);
        rep(i, k)
        {
            cin >> l[i];
        }
        pol p(l);
        rep(i, k)
        {
            cin >> l[i];
        }
        pol q(l);
        rat y1(p,q);
        rep(i, k)
        {
            cin >> l[i];
        }
        p.cof = l;
        rep(i, k)
        {
            cin >> l[i];
        }
        q.cof = l;
        rat y2(p,q);
        double start = 0;
        double end = d;
        rep(_, 100)
        {
            mid = (start + end) / 2;
            double area1 = simpsons_rule(y1, 0, w, 2e3);
            double area2 = simpsons_rule(y2, 0, w, 2e3);

            if (area1 - area2 > a)
                end = mid;
            else
                start = mid;
        }
        cout << (start + end) / 2 << '\n';
    }
    return 0;
}
