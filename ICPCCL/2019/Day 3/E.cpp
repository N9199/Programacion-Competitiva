#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)

int n, m, x, y;

vi whites;

vector<vi> dpw;
vector<vi> dpb;

int f(int i, int k, bool white)
{
    if (white)
    {
        if (i == m and k < x)
            return 1e8;
        if (i == m)
            return 0;
        if (dpw[i][k] != -1)
            return dpw[i][k];
        if (k < x)
            return dpw[i][k] = f(i + 1, k + 1, true) + n - whites[i];
        if (k == y)
            return dpw[i][k] = f(i + 1, 1, false) + whites[i];
        return dpw[i][k] = min(f(i + 1, k + 1, true) + n - whites[i], f(i + 1, 1, false) + whites[i]);
    }
    else
    {
        if (i == m and k < x)
            return 1e8;
        if (i == m)
            return 0;
        if (dpb[i][k] != -1)
            return dpb[i][k];
        if (k < x)
            return dpb[i][k] = f(i + 1, k + 1, false) + whites[i];
        if (k == y)
            return dpb[i][k] = f(i + 1, 1, true) + n - whites[i];
        return dpb[i][k] = min(f(i + 1, k + 1, false) + whites[i], f(i + 1, 1, true) + n - whites[i]);
    }
}

int main()
{
    cin >> n >> m >> x >> y;
    whites.assign(m, 0);
    dpw.assign(m, vi(y + 1, -1));
    dpb.assign(m, vi(y + 1, -1));
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, s.length())
        {
            if (s[j] == '.')
                whites[j]++;
        }
    }
    cout << min(f(0, 0, 0), f(0, 0, 1)) << '\n';
}