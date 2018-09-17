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
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

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
    vector<double> cofs;
    int deg;
    pol(vector<double> cofs) : cofs(cofs), deg(cofs.size() - 1)
    {
        invrep(i, 0, deg + 1)
        {
            if (cofs[i] == 0)
                deg--;
            else
                break;
        }
    }

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

    pol operator*(const pol &o) const
    {
        vector<double> c(deg + o.deg + 1);
        rep(i, deg + 1)
        {
            rep(j, o.deg + 1)
            {
                c[i + j] += cofs[i] * o.cofs[j];
            }
        }
        return pol(c);
    }

    pol integrate()
    {
        vector<double> c(deg + 2);
        repx(i, 1, deg + 2)
        {
            c[i] = cofs[i - 1] / (double)i;
        }
        return pol(c);
    }

    friend ostream &operator<<(ostream &str, const pol &a);
};

ostream &operator<<(ostream &strm, const pol &a)
{
    bool flag = false;
    rep(i, a.deg + 1)
    {
        if (a.cofs[i] == 0)
            continue;

        if (flag)
            if (a.cofs[i] > 0)
                strm << " + ";
            else
                strm << " - ";
        else
            flag = true;
        if (i > 0)
        {
            if (abs(a.cofs[i]) != 1)
                strm << abs(a.cofs[i]);
            strm << "x^" << i;
        }
        else
        {
            strm << a.cofs[i];
        }
    }
    return strm;
}

double integrate(pol p, double a, double b)
{
    pol f = p.integrate();
    return f(b) - f(a);
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
        vector<double> temp(n);
        rep(i, n)
        {
            cin >> temp[i];
        }
        pol p(temp);
        pol f = p * p;
        double x_low, x_high;
        int mark;
        cin >> x_low >> x_high >> mark;
        double total = PI * integrate(f, x_low, x_high);
        cout << "Case " << ncase << ": " << total << '\n';

        bool flag = false;
        debugx(total - mark);
        int count = 0;
        double x = x_low;
        while (total > mark and count++ < 8)
        {
            if (flag)
                cout << ' ';
            else
                flag = true;

            double start = x_low;
            double end = x_high;
            rep(_, 40)
            {
                double mid = (start + end) * 0.5;
                double temp = PI * integrate(f, x_low, mid);
                if (temp > mark)
                    end = mid;
                else
                    start = mid;
            }
            cout << (start + end) * 0.5 - x;
            total -= PI * integrate(f, x_low, (start + end) * 0.5);
            x_low = (start + end) * 0.5;
        }
        if (flag)
            cout << '\n';
        else
            cout << "insufficient volume\n";
    }

    return 0;
}
