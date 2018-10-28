#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;

typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << ' ' << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int main()
{
    ll n;
    cin >> n;
    ll m = n * (n + 1) / 2;
    ll sum = 0;
    if (n % 4 == 0)
    {
        cout << 0 << '\n';
        ll i = 0;
        cout << n / 2;
        while (sum < m / 2)
        {
            cout << ' ' << i + 1 << ' ' << n - i;
            sum += n + 1;
            i++;
        }
    }
    else if (n % 4 == 1)
    {
        cout << 1 << '\n';
        ll i = 2;
        cout << n / 2;
        while (sum < m / 2)
        {
            cout << ' ' << i << ' ' << n - i + 2;
            sum += n + 2;
            i++;
        }
    }
    else if (n % 4 == 2)
    {
        cout << 1 << '\n';
        ll i = 4;
        cout << n / 2 << ' ';
        cout << 1;
        sum = 1;
        while (2ll * sum + 2ll < m)
        {
            cout << ' ' << i << ' ' << i + 1;
            sum += 2 * i + 1;
            i += 4;
        }
    }
    else
    {
        cout << 0 << '\n';
        ll i = 1;
        cout << n / 2 + 1;
        while (sum < m / 2)
        {
            cout << ' ' << i << ' ' << i + 1;
            sum += 2 * i + 1;
            i += 4;
        }
    }
    cout << '\n';
    return 0;
}