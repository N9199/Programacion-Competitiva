
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, ll> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << ' ' << p.second;
    return os;
}

namespace FastIO
{
    const int BSZ = 1 << 15; ////// INPUT
    char ibuf[BSZ];
    int ipos, ilen;
    char nc()
    { // next char
        if (ipos == ilen)
        {
            ipos = 0;
            ilen = fread(ibuf, 1, BSZ, stdin);
            if (!ilen)
                return EOF;
        }
        return ibuf[ipos++];
    }
    void rs(string &x)
    { // read str
        char ch;
        while (isspace(ch = nc()))
            ;
        do
        {
            x += ch;
        } while (!isspace(ch = nc()) && ch != EOF);
    }
    template <class T>
    void ri(T &x)
    { // read int or ll
        char ch;
        int sgn = 1;
        while (!isdigit(ch = nc()))
            if (ch == '-')
                sgn *= -1;
        x = ch - '0';
        while (isdigit(ch = nc()))
            x = x * 10 + (ch - '0');
        x *= sgn;
    }
    template <class T, class... Ts>
    void ri(T &t, Ts &... ts)
    {
        ri(t);
        ri(ts...);
    } // read ints
    ////// OUTPUT (call initO() at start)
    char obuf[BSZ], numBuf[100];
    int opos;
    void flushOut()
    {
        fwrite(obuf, 1, opos, stdout);
        opos = 0;
    }
    void wc(char c)
    { // write char
        if (opos == BSZ)
            flushOut();
        obuf[opos++] = c;
    }
    void ws(string s)
    {
        for (auto &c : s)
            wc(c);
    } // write str
    template <class T>
    void wi(T x, char after = '\0')
    { /// write int
        if (x < 0)
            wc('-'), x *= -1;
        int len = 0;
        for (; x >= 10; x /= 10)
            numBuf[len++] = '0' + (x % 10);
        wc('0' + x);
        invrep(i, 0, len)
            wc(numBuf[i]);
        if (after)
            wc(after);
    }
    void initO() { assert(atexit(flushOut) == 0); } /// auto-flush output
} // namespace FastIO

template <int SZ>
struct Sieve
{
    bitset<SZ> pri;
    vi pr;
    constexpr Sieve()
    { // cum[i] = # of primes up to i
        pri.set();
        pri[0] = pri[1] = 0;
        for (int i = 4; i < SZ; i += 2)
            pri[i] = 0;
        for (int i = 3; i * i < SZ; i += 2)
            if (pri[i])
                for (int j = i * i; j < SZ; j += i * 2)
                    pri[j] = 0;
        rep(i, SZ) if (pri[i]) pr.pb(i);
    }
};
const Sieve<1 << 21> S;

ull modMul(ull a, ull b, const ull mod)
{
    ll ret = a * b - mod * (ull)((ld)a * b / mod);
    return ret + ((ret < 0) - (ret >= (ll)mod)) * mod;
}
ull modPow(ull a, ull b, const ull mod)
{
    if (b == 0)
        return 1;
    ull res = modPow(a, b / 2, mod);
    res = modMul(res, res, mod);
    return b & 1 ? modMul(res, a, mod) : res;
}

bool prime(ull n)
{ // not ll!
    if (n < 2 || n % 6 % 4 != 1)
        return n - 2 < 2;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n - 1), d = n >> s;
    for (auto &a : A)
    { // ^ count trailing zeroes
        ull p = modPow(a, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modMul(p, p, n);
        if (p != n - 1 && i != s)
            return 0;
    }
    return 1;
}

ull pollard(ull n)
{
    auto f = [n](ull x) { return (modMul(x, x, n) + 1) % n; };
    if (!(n & 1))
        return 2;
    for (ull i = 2;; ++i)
    {
        ull x = i, y = f(x), p;
        while ((p = __gcd(n + y - x, n)) == 1)
            x = f(x), y = f(f(y));
        if (p != n)
            return p;
    }
}
vector<pair<ull, ull>> factor(ll d)
{
    vector<pair<ull, ull>> res;
    for (auto &t : S.pr)
    {
        if ((ull)t * t > d)
            break;
        if (d % t == 0)
        {
            res.pb({t, 0});
            while (d % t == 0)
                d /= t, res.back().second++;
        }
    }
    if (prime(d))
        res.pb({d, 1}), d = 1;
    if (d == 1)
        return res; // now a product of at most 2 primes
    ll c = pollard(d);
    d /= c;
    if (d > c)
        swap(d, c);
    if (c == d)
        res.pb({c, 2});
    else
        res.pb({c, 1}), res.pb({d, 1});
    return res;
}

int main()
{
    FastIO::initO();
    int t;
    ll n;
    FastIO::ri(t);
    vector<pair<ull, ull>> factors;
    factors.reserve(100);
    rep(_, t)
    {
        FastIO::ri(n);
        factors = factor(n);
        bool flag = false;
        for (int i = 0; i < factors.size();)
        {
            if (flag)
                FastIO::wc(' ');
            FastIO::wi(factors[i].first);
            flag = true;
            if (--factors[i].second == 0)
                i++;
        }
        FastIO::wc('\n');
    }
}