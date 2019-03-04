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

vi primes;

void sieve()
{
    int n = 1e6;

    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);
}

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

int main()
{
    sieve();
    string s;
    vi char_count;
    vi prime_count;

    while (cin >> s)
    {
        debugx(s);
        int len = s.size();
        debugx(len);
        char_count.assign(26, 0);
        prime_count.assign(max(len + 1, 6), 0);
        rep(i, len)
            char_count[s[i] - 'a']++;

        for (int p : primes)
        {
            if (p > len)
                break;

            debugx(p);
            int n = len;
            while ((n /= p) > 0)
                prime_count[p] += n;
        }
        debugv(prime_count);

        for (int chr : char_count)
        {
            if (chr > 1)
            {
                for (int p : primes)
                {
                    if (p > chr)
                        break;

                    debugx(p);
                    int n = chr;
                    while ((n /= p) > 0)
                        prime_count[p] -= n;
                }
            }
        }
        debugv(prime_count);

        int m = min(prime_count[2], prime_count[5]);
        prime_count[2] -= m;
        prime_count[5] -= m;

        int ans = 1;
        for (int p : primes)
        {
            if (p > len)
                break;

            if (prime_count[p] > 0)
                ans = mulmod(ans, fastPow(p, prime_count[p], 10), 10);
        }

        cout << ans << '\n';
    }
}