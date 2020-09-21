#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
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
#define debugx(x) cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v)        \
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

int n;
vii items;
inline int dist(int i, int j) { return (items[i].first - items[j].first) * (items[i].first - items[j].first) + (items[i].second - items[j].second) * (items[i].second - items[j].second); }

inline bool check(int b, int i) { return b & (1 << i); }

vector<ll> dp;
ll func(int b)
{
    if (dp[b] != -1)
        return dp[b];

    ll ans = 1e9;
    invrep(i, 0, n)
    {
        if (check(b, i))
        {
            ans = min(ans, func(b & ~(1 << i)) + 2 * dist(i, n));
            invrep(j, 0, i)
            {
                if (check(b, j))
                    ans = min(ans, func(b & ~(1 << i) & ~(1 << j)) + dist(n, i) + dist(i, j) + dist(j, n));
            }
            return dp[b] = ans;
        }
    }
    return dp[b] = ans;
}

string path(int b)
{
    if (b == 0)
        return "0";
    string ans = "0 ";
    invrep(i, 0, n)
    {
        if (check(b, i))
        {
            invrep(j, 0, i)
            {
                if (check(b, j) and dp[b] - dp[b & ~(1 << i) & ~(1 << j)] == dist(n, i) + dist(n, j) + dist(i, j))
                {
                    ans += to_string(i + 1) + " " + to_string(j + 1) + " " + path(b & ~(1 << i) & ~(1 << j));
                    return ans;
                }
            }
            if (dp[b] - dp[b & ~(1 << i)] == 2 * dist(n, i))
            {
                ans += to_string(i + 1) + " " + path(b & ~(1 << i));
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cin >> n;
    dp.assign(1 << n, -1);
    dp[0] = 0;
    items.assign(n + 1, ii(0,0));
    items[n] = {x, y};
    rep(i, n)
    {
        cin >> x >> y;
        items[i] = {x, y};
    }
    cout << func((1 << n) - 1) << '\n';
    cout << path((1 << n) - 1) << '\n';
}