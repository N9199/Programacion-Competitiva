#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vii> wgraph;
typedef vector<vi> graph;
typedef vector<vll> vvll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto &v : m)         \
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

int n;
vii items;
inline ll dist(int i, int j)
{
    return (items[i].first - items[j].first) * (items[i].first - items[j].first) + (items[i].second - items[j].second) * (items[i].second - items[j].second);
}

inline bool marked(int i, int mask)
{
    return (mask & (1 << i));
}

vvll dp;
wgraph origin;
ll func(int mask, int s, int last)
{
    if (mask == (1 << n) - 1)
        return dp[s][mask] = 0;
    if (dp[s][mask] != -1)
        return dp[s][mask];
    ll ans = 9e18;
    ll temp, temp2, temp3;
    vi in = {mask, s, last};
    rep(i, n)
    {
        int a = 0;
        if (marked(i, mask))
            continue;

        temp = dist(i, last); //Distance to i from wherever it was, it may be the origin
        if ((mask | (1 << i)) < (1 << n) - 1 and not s)
        {
            temp3 = func(mask | (1 << i), 1, i);
            temp2 = dist(i, n) + func(mask | (1 << i), 0, n);
            if (temp3 <= temp2)
            {
                a++;
                temp2 = temp3;
            }
            temp2 += temp;
            if (temp2 < ans)
            {
                ans = temp2;
                origin[s][mask] = {i, a};
            }
        }
        else
        {
            temp2 = temp + dist(i, n) + func(mask | (1 << i), 0, n);
            if (temp2 < ans)
            {
                ans = temp2;
                origin[s][mask] = {i, 0};
            }
        }
    }
    return dp[s][mask] = ans;
}

string path()
{
    ll bound = dp[0][0];
    string ans = "0 ";
    int marked = 0;
    ll accum = 0;
    int next = 0;
    int last = n;
    int s = 0;
    while (marked < (1 << n) - 1)
    {
        next = origin[s][marked].first;
        s = origin[s][marked].second;
        marked = marked | (1 << next);
        accum += dist(next, last);
        ans += to_string(next + 1) + " ";
        last = next;
        if (s == 0)
        {
            ans += "0 ";
            accum += dist(next, n);
            last = n;
        }
    }
    debugx(accum);
    assert(bound == accum);
    return ans;
}

int main(int argc, char const *argv[])
{
    int x, y;
    cin >> x >> y;
    cin >> n;
    dp.assign(2, vll(1 << n, -1));
    origin.assign(2, vii(1 << n, {-1, -1}));
    items.resize(n + 1);
    items[n] = {x, y};
    rep(i, n)
    {
        cin >> x >> y;
        items[i] = {x, y};
    }
    debugv(items);
    cout << func(0, 0, n) << '\n';
    cout << path() << '\n';

    return 0;
}
