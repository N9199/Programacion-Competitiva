#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define double long double

typedef long long ll;
int n, W;
double x, y;
vector<pair<double, double>> H;

vector<double> Acum;

double Integral(double x)
{
    if (x <= H[0].ff)
        return 0;
    if (x >= H[n - 1].ff)
        return Acum[n - 1];
    int l = 0;
    int r = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (H[m].ff > x)
            r = m;
        else
            l = m + 1;
    }

    return Acum[l - 1] + (x - H[l - 1].ff) * (H[l - 1].ss + 0.5*((x - H[l - 1].ff) *(H[l].ss -  H[l - 1].ss) / (H[l].ff - H[l - 1].ff)));
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(6);
    cin >> n >> W;
    Acum.resize(n);

    double x_, y_;
    Acum[0] = 0;
    rep(i, n)
    {
        cin >> x >> y;
        H.emplace_back(x, y);
        if (i > 0)
            Acum[i] = Acum[i - 1] + ((x - x_) * (y + y_)) / 2.0;
        x_ = x;
        y_ = y;
    }

    rep(i, n) cerr << Integral(H[i].ff + 1) << ' ';
    cerr << '\n';
    double best = 0;
    rep(i, n)
    {
        best = max(best, Integral(H[i].ff + W) - Integral(H[i].ff));
        best = max(best, Integral(H[i].ff) - Integral(H[i].ff - W));
    }
    cout << best / (double)W << '\n';
}