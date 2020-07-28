#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
typedef long long ll;

int r;
vector<int> s;

ll DP[(1 << 15)][15];

ll dp(int i, int lev)
{
    if (lev == -1) return 0;

    if (DP[i][lev] != -1) return DP[i][lev];

    ll ans = 1e15;

    int j = i / (1 << lev);
    int l = (j & 1) ? ((j - 1) * (1 << lev)) : ((j + 1) * (1 << lev));
    int r = l + (1 << lev);
    repx(k, l, r) ans = min(ans, dp(k, lev - 1) + (max(0, s[k] - s[i]) * max(0, s[k] - s[i])));

    return DP[i][lev] = ans + dp(i, lev - 1);
}

int main()
{
    cin >> r;

    s.resize(1 << r);
    rep(i, 1 << r) cin >> s[i];

    memset(DP, -1, sizeof DP);

    cout << dp(0, r - 1) << '\n';
}