#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)  //\
    cerr << #v << ":";                          \
    rep(i, (int)v.size()) cerr << ", " << v[i]; \
    cerr << endl
#define debugm(m)  //\
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

ll mulmod(ull a, ull b, ull c)
{
    ull x = 0, y = a % c;
    while (b)
    {
        if (b & 1)
            x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1)
            ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret;
}

bool isPrime(ll n)
{
    unordered_set<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    if (n <= 31)
        return p.find(n) != p.end();
    if (n & 1 == 0)
        return false;
    vi a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0)
    {
        s++;
        d >>= 1;
    }

    rep(i, a.size())
    {
        ll fp = fastPow(a[i], d, n);
        bool comp = (fp != 1);
        if (comp)
            rep(j, s)
            {
                if (fp == n - 1)
                {
                    comp = false;
                    break;
                }

                fp = mulmod(fp, fp, n);
            }
        if (comp)
            return false;
    }
    return true;
}

int main()
{
    ll n = 2000000;
    ll sum = 0;
    rep(p, n)
    {
        sum += isPrime(p) ? p : 0;
        //cout << sum << '\n';
    }
    cout << "Ans: " << sum << endl;
    return 0;
}