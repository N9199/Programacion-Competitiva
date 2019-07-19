#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
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

vi sieve(int n)
{
    vi primes;

    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);

    return primes;
}

umap<int, int> factorialFactorization(int n, vi &primes)
{
    umap<int, int> p2e;
    for (auto p : primes)
    {
        if (p > n)
            break;
        int e = 0;
        int tmp = n;
        while ((tmp /= p) > 0)
            e += tmp;
        if (e > 0)
            p2e[p] = e;
    }
    return p2e;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vi primes = sieve(1000000);
    while (cin >> s)
    {
        vi a(26);
        int n = 0;
        for (char c : s)
        {
            a[c - 'a']++;
            n++;
        }
        umap<int, int> val = factorialFactorization(n, primes);
        for (int c : a)
        {
            umap<int, int> temp = factorialFactorization(c, primes);
            for (auto it = temp.begin(); it != temp.end(); it++)
            {
                val[it->first] -= it->second;
            }
        }
        int tens = min(val[2], val[5]);
        val[2] -= tens;
        val[5] -= tens;
        if (val[5] > 0)
        {
            cout << 5 << '\n';
        }
        else
        {
            int ans = 1;
            for (auto it = val.begin(); it != val.end(); it++)
            {
                if (it->first != 2)
                    val[it->first] %= 4;

                rep(i, val[it->first])
                {
                    ans *= (it->first);
                    ans %= 10;
                }
            }
            cout << ans << '\n';
        }
    }
}