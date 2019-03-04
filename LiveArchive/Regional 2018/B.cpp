#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define rep(i, n) for (int i = 0; i < n; i++)

#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl;

int main()
{
    int n;
    cin >> n;
    vi L(n);
    vi P(n);
    rep(i, n)
    {
        cin >> L[i];
        if (i > 0)
            P[i] = L[i] + P[i - 1];
        else
            P[i] = L[i];
    }
    debugv(P);
    ll tot = P[n - 1];
    int i = 0, j = 1;
    ll sum = P[i] - P[j];
    //Use sums of lengths to check

    return 0;
}