//UVA 11395 Sigma Function
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define rep(i, n) for (int i = 0; i < n; i++)
#define tr(e, v) for (auto e = v.begin(); e != v.end(); e++)
#define trv(e, v) for (auto e = v.rbegin(); e != v.rend(); e--)

#define umap unordered_map

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll temp;
    while (cin >> temp)
    {
        if (temp == 0)
            return 0;
        cout << temp - (ll)floor(sqrt(temp)) - (ll)floor(sqrt(temp / 2)) << '\n';
    }

    return 0;
}
