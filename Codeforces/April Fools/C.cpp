#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back
#define debugx(x) cerr << #x << ": " << x << endl

#define log(n) (31 - __builtin_clz(n))

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    rep(i, log(n))
    {
        ans += (1 << i) & n;
    }
    cout << ans << '\n';
}