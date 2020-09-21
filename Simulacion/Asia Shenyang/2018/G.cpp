#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

// Reps are inclusive exclusive (i.e. range is [a,b))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

// Base two log for ints and for ll
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) //cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v) //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m) //          \
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

vi is_prime;
vi sieve(int n)
{
    vi primes;
    is_prime.assign(n + 1, 0);
    rep(i, n + 1) is_prime[i] = i;

    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i] == i) for (int j = i * i; j <= n; j += i) if (is_prime[j] == j)
        is_prime[j] = i;

    repx(i, 2, n + 1) if (is_prime[i] == i) primes.eb(i);

    return primes;
}

umap<int, ii> memo;

ii complex_factor(int n)
{
    if (memo.find(n) != memo.end())
        return memo[n];

    int j = sqrt(n) + 1;
    rep(i, sqrt(n) + 1)
    {
        while (j * j + i * i > n)
            j--;
        if (j * j + i * i == n)
            return memo[n] = {i, j};
    }
}

vi factor(int n)
{
    vi ans;
    while (n > 1)
    {
        ans.eb(is_prime[n]);
        n /= is_prime[n];
    }
    return ans;
}

ii multiply(const ii &a, const ii &b) { return make_pair(a.first * b.first - a.second * b.second, a.second * b.first + a.first * b.second); }

inline int const hashh(const ii &p) { return 6000 * p.first + p.second; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    auto primes = sieve(1e7);
    umap<int, ll> points;
    int x, y, k, w;
    int T;
    cin >> T;
    int n, m;
    rep(_, T)
    {
        cout << "Case #" << _ + 1 << ":\n";
        cin >> n >> m;
        debugx("1");
        rep(i, n)
        {
            cin >> x >> y >> w;
            points[hashh(make_pair(x, y))] = w;
        }
        int lastans = 0;
        rep(i, m)
        {
            debugx("2");
            debugx(i);
            int q;
            cin >> q;
            if (q == 1)
            {
                cin >> x >> y >> w;
                points[hashh(make_pair((x + lastans) % 6000 + 1, (y + lastans) % 6000 + 1))] = w;
                continue;
            }
            if (q == 2)
            {
                cin >> x >> y;
                points.erase(hashh(ii((x + lastans) % 6000 + 1, (y + lastans) % 6000 + 1)));
                continue;
            }
            cin >> x >> y >> k;
            x = (x + lastans) % 6000 + 1;
            y = (y + lastans) % 6000 + 1;
            if (q == 3)
                cin >> w;
            debugx(q);
            set<ii> temp_p;
            stack<pair<int, ii>> s;
            auto factors = factor(k);
            vii p_factors;
            debugx("Hola");
            ll temp = 1;
            int count = 0;
            for (auto p : factors)
                if (p % 4 == 1)
                    p_factors.eb(complex_factor(p));
                else if (p % 4 == 3)
                    temp *= p;
                else
                    count++;

            if (temp != pow(floor(sqrt(temp)), 2))
                continue;
            debugx("Hola2");
            if (p_factors.size() > 0)
            {
                s.emplace(1, p_factors[0]);
                while (!s.empty())
                {
                    auto u = s.top();
                    s.pop();
                    debugx(u);
                    debugx(s.size());
                    if (u.first == p_factors.size())
                    {
                        temp_p.emplace(u.second);
                        continue;
                    }
                    s.emplace(u.first + 1, multiply(u.second, p_factors[u.first]));
                    s.emplace(u.first + 1, multiply(u.second, ii(p_factors[u.first].first, -p_factors[u.first].second)));
                }
            }
            else
            {
                temp_p.emplace(1, 0);
            }
            debugx("Hola3");
            set<ii> temp_p2;
            for (auto p : temp_p)
            {
                ii temp2 = p;
                if (count % 2)
                    temp2 = multiply(p, ii(1, 1));
                if (count)
                    temp2 = multiply(ii(1 << (count / 2), 0), temp2);
                temp2 = {temp * temp2.first, temp * temp2.second}; //<---
                temp_p2.emplace(temp2);
                temp_p2.emplace(temp2.first, -temp2.second);
                temp2 = multiply(ii(0, 1), temp2);
                temp_p2.emplace(temp2);
                temp_p2.emplace(temp2.first, -temp2.second);
                temp2 = multiply(ii(0, 1), temp2);
                temp_p2.emplace(temp2);
                temp_p2.emplace(temp2.first, -temp2.second);
                temp2 = multiply(ii(0, 1), temp2);
                temp_p2.emplace(temp2);
                temp_p2.emplace(temp2.first, -temp2.second);
            }
            ll ans = 0;
            for (auto p : temp_p2)
            {
                if (q == 3)
                {
                    if (points.find(hashh(ii(x + p.first, y + p.second))) != points.end())
                    {
                        points[hashh(ii(x + p.first, y + p.second))] += w;
                    }
                }
                else
                {
                    if (points.find(hashh(ii(x + p.first, y + p.second))) != points.end())
                    {
                        ans += points[hashh(ii(x + p.first, y + p.second))];
                    }
                }
            }
            if (q == 4)
            {
                cout << ans << '\n';
                lastans = ans;
            }
        }
    }
}