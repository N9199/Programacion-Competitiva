#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, x, n) for (int i = x; i < (int)n; ++i)
#define invrep(i, n) for (int i = n; i--;)
#define pb push_back
#define CHECK_BIT(var, pos) ((var) & (1LL << (pos)))

ll func(ll n)
{
    ll k = (ll)floor(log2(n));
    if (k == (ll)log2(n))
    {
        return k * pow(2, k - 1) + 1;
    }
    ll c = (ll)log2(n - (ll)pow(2, k));
    if (c + 1 > (ll)floor(log2(n - (ll)pow(2, k))))
    {
        return (ll)log2(n) * pow(2, log2(n) - 1) + 1 + func(pow(2, c)) - func(pow(2, c - 1)) + func(n - (ll)pow(2, k)) + n - (ll)pow(2, k);
    }
    return (ll)log2(n) * pow(2, log2(n) - 1) + 1 + func(pow(2, c)) - func(pow(2, c - 1)) + func(n - (ll)pow(2, k));
}
ll func2(ll n)
{
    if (n <= 1ll)
    {
        return 1ll;
    }
    ll sum = 0ll;
    ll temp = n;
    while (temp > 0ll)
    {
        sum += temp % (2ll);
        temp /= 2ll;
    }
    return func2(n - 1ll) + sum;
}
int main()
{
    ll v = 15ll;
    cout << "func1:" << func(v) << endl;
    cout << "func2:" << func2(v) << endl;
    return 0;
}