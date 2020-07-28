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
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back
#define gcd __gcd

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) //        \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m) //            \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

unordered_set<int> primes;
void sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.emplace(i);
}

vi dp;
graph g;
graph invg;
int func(int u)
{
    if (dp[u] != -1)
        return dp[u];
    if (g[u].size() == 0)
        return 0;
    dp[u] = func(g[u][0]);
    for (auto v : g[u])
        dp[u] = gcd(dp[u], func(v));
    return dp[u];
}
bool ans = true;
int fix(int u)
{
    // 2,4,16,32,32
    // 2,6,12,36,36
    if(!ans)
        return -1;
    debugx("fixing");
    debugx(u);
    if (invg[u].size() == 0)
    {
        if (dp[u] == 1)
        {
            ans = false;
            debugx(-1);
            return -1;
        }
        for (auto p : primes)
            if (dp[u] % p == 0)
            {
                dp[u] /= p;
                debugx(p);
                return p;
            }
        int p = dp[u];
        dp[u] /= p;
        return p;
    }
    else
    {
        int v = invg[u][0];
        debugx(v);
        if (dp[u] == dp[v])
        {
            ans = false;
            return -1;
        }
        if (primes.find(dp[u] / dp[v]) == primes.end())
        {
            for (auto p : primes)
                if ((dp[u] / dp[v]) % p == 0)
                {
                    dp[u] /= p;
                    return p;
                }
        }
        int p = fix(v);
        dp[u] /= p;
        debugx(p);
        return p;
    }
}
void find(int u)
{
    if (!ans)
        return;
    for (auto v : g[u])
    {
        if (dp[u] == dp[v])
        {
            debugx(u);
            fix(u);
            debugv(dp);
        }
        find(v);
    }
}
int main()
{
#ifdef ONLINE_JUDGE
    freopen("divisibility-tree.out", "w", stdout);
    freopen("divisibility-tree.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve(1e5);
    int n;
    cin >> n;
    g.resize(n);
    invg.resize(n);
    dp.assign(n, -1);
    debugx("?");
    rep(i, n)
    {
        int temp;
        cin >> temp >> dp[i];
        if (temp == -1)
            continue;
        temp--;
        g[temp].eb(i);
        invg[i].eb(temp);
    }
    debugx("?");
    if (ans)
        func(0);
    debugv(dp);
    if (ans)
        find(0);
    debugv(dp);
    if (!ans)
        rep(i, n) dp[i] = -1;
    debugx(ans);
    rep(i, n)
    {
        if (i > 0)
            cout << ' ';
        cout << dp[i];
    }
    cout << '\n';
}