#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, x, n) for (int i = x; i < (int)n; ++i)
#define pb push_back

graph dp = graph(5001, vi(5001, -1));

ll func(int n, int k)
{
    if (n < k + 1)
    {
        return 0l;
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    if (n == 1 || k == 0 || n == k + 1)
    {
        return dp[n][k] = 1l;
    }
    return dp[n][k] = ((n - k) * func(n - 1, k - 1) + (k + 1) * func(n - 1, k)) % 1000000007l;
}

int main()
{
    int n, q;
    while (cin >> n >> q)
    {
        int temp;
        rep(i, q)
        {
            cin >> temp;
            int k = min(5000, temp);
            ll res = 0l;
            rep(i, k)
            {
                res = res % 1000000007l + func(n, i) % 1000000007l;
                res %= 1000000007l;
            }
            if (i < q - 1)
            {
                cout << res << " ";
            }
            else
            {
                cout << res << "\n";
            }
        }
    }
    return 0;
}