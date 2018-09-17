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

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v) \
    //cerr << #v << ":";                          \
    rep(i, (int)v.size()) cerr << ", " << v[i]; \
    cerr << endl
#define debugm(m) \
    //cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) \
    //cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

unordered_set<int> primes;

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
    //if(n <= N) return P[n] == n;
    unordered_set<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    if (n <= 31)
        return p.find(n) != p.end();
    if (n == 2)
        return true;
    if (n % 2 == 0 or n <= 1)
        return false;
    vi a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0)
    {
        s++;
        d >>= 1;
    }

    for (int i = 0; i < 7; i++)
    {
        ll fp = fastPow(a[i], d, n);
        bool comp = (fp != 1);
        if (comp)
            for (int j = 0; j < s; j++)
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

unordered_map<int, vi> adjacent_saved;

vi adjacent(int n)
{
    if (n == 1)
        return {2, 4, 6, 8};

    if (adjacent_saved.find(n) != adjacent_saved.end())
        return adjacent_saved[n];

    vi temp(4);
    temp[0] = n - 1;
    temp[1] = n + 1;
    int k = ceil((sqrt((double)n) + 1) / 2);
    function<int(int)> p1 = [](int n) {
        return 1 + 2 * (n - 1) + 4 * (n - 1) * (n - 2);
    };

    function<int(int)> p2 = [](int n) {
        return 1 + 4 * (n - 1) + 4 * (n - 1) * (n - 2);
    };

    function<int(int)> p3 = [](int n) {
        return 1 + 6 * (n - 1) + 4 * (n - 1) * (n - 2);
    };

    function<int(int)> p4 = [](int n) {
        return (2 * n - 1) * (2 * n - 1);
    };

    if (p1(k) == n)
    {
        temp[2] = p1(k + 1) - 1;
        temp[3] = p1(k + 1) + 1;
    }
    else if (p2(k) == n)
    {
        temp[2] = p2(k + 1) - 1;
        temp[3] = p2(k + 1) + 1;
    }
    else if (p3(k) == n)
    {
        temp[2] = p3(k + 1) - 1;
        temp[3] = p3(k + 1) + 1;
    }
    else if (p4(k) == n)
    {
        temp[2] = p4(k - 1) + 1;
        temp[3] = p4(k + 1) - 1;
    }
    else if (p4(k - 1) + 1 == n)
    {
        temp[2] = p4(k) + 2;
        temp[3] = p4(k);
    }
    else if (p1(k) < n and n < p2(k))
    {
        temp[2] = n + 3 + 8 * (k - 1);
        temp[3] = n - 3 - 8 * (k - 2);
    }
    else if (p2(k) < n and n < p3(k))
    {
        temp[2] = n + 5 + 8 * k;
        temp[3] = n - 5 - 8 * (k - 1);
    }
    else if (p3(k) < n and n < p4(k))
    {
        temp[2] = n + 7 + 8 * (k - 1);
        temp[3] = n - 7 - 8 * (k - 2);
    }
    else
    {
        temp[2] = n + 1 + 8 * k;
        temp[3] = n - 1 - 8 * (k - 1);
    }

    return adjacent_saved[n] = temp;
}

string bfs(int start, int end)
{
    debugx(start);
    debugx(end);
    if (isPrime(start) or isPrime(end))
        return "impossible";

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    unordered_set<int> visited;
    visited.emplace(start);
    visited.emplace(end);
    q1.emplace(start, 0);
    q2.emplace(end, 0);
    m1[start] = 0;
    m2[end] = 0;
    bool c = true;

    while (!q1.empty() and !q2.empty())
    {
        int u, d;
        if (c)
        {
            u = q1.front().first;
            d = q1.front().second;
            q1.pop();
        }
        else
        {
            u = q2.front().first;
            d = q2.front().second;
            q2.pop();
        }
        debugx(u);
        for (int v : adjacent(u))
        {
            debugx(v);
            if (primes.find(v) == primes.end())
            {
                if (isPrime(v))
                    primes.emplace(v);
                else
                {
                    if (c)
                    {
                        if (m2.find(v) != m2.end())
                            return to_string(m2[v] + d + 1);
                    }
                    else if (m1.find(v) != m1.end())
                        return to_string(m1[v] + d + 1);

                    if (visited.find(v) == visited.end())
                    {
                        if (c)
                        {
                            q1.emplace(v, d + 1);
                            m1[v] = d + 1;
                        }
                        else
                        {
                            q2.emplace(v, d + 1);
                            m2[v] = d + 1;
                        }
                        visited.emplace(v);
                        debugx("added");
                    }
                }
            }
        }
        c = !c;
    }

    return "impossible";
}

int main()
{
    int c = 0;
    int s, e;
    //assert(isPrime(1e9+7));
    while (cin >> s >> e)
    {
        cout << "Case " << ++c << ": " << bfs(s, e) << '\n';
    }
    return 0;
}