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

vector<ll> dp;

ll func(int mask)
{
    if (dp[mask] != -1)
        return dp[mask];
    ll ans = 1e9;
    invrep(i, 0, n)
    {
        if (marked(i, mask))
        {
            ans = min(ans, func(mask & ~(1 << i)) + 2 * dist(n, i));
            invrep(j, 0, i)
            {
                if (marked(j, mask))
                {
                    ans = min(ans, func(mask & ~(1 << i) & ~(1 << j)) + dist(n, i) + dist(n, j) + dist(i, j));
                }
            }
            return dp[mask] = ans;
        }
    }
    return dp[mask] = ans;
}

string path(int mask)
{
    //debugx(mask);
    if (mask == 0)
        return "0";
    string ans = "0 ";
    invrep(i, 0, n)
    {
        if (marked(i, mask))
        {
            ans += to_string(i+1);
            ans += " ";
            invrep(j, 0, i)
            {
                if (marked(j, mask) and dp[mask] - dp[mask & ~(1 << i) & ~(1 << j)] == dist(n, i) + dist(n, j) + dist(i, j))
                {
                    ans += to_string(j+1);
                    ans += " ";
                    ans += path(mask & ~(1 << i) & ~(1 << j));
                    return ans;
                }
            }
            if (dp[mask] - dp[mask & ~(1 << i)] == 2 * dist(n, i))
            {
                ans += path(mask & ~(1 << i));
                return ans;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int x, y;
    cin >> x >> y;
    cin >> n;
    dp.assign((1 << n), -1);
    dp[0] = 0;
    items.resize(n + 1);
    items[n] = {x, y};
    rep(i, n)
    {
        cin >> x >> y;
        items[i] = {x, y};
    }
    //debugv(items);
    cout << func((1 << n) - 1) << '\n';
    //debugv(dp);
    cout << path((1 << n) - 1) << '\n';

    return 0;
}
