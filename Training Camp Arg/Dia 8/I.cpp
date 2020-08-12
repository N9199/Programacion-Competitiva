#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

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

inline int set_minus(int mask1, int mask2)
{
    return mask1 & ~(mask2);
}
inline int itm(int i) { return 1 << i; }
inline bool subset(int mask1, int mask2)
{
    return (mask1 & mask2) == mask1;
}
vi itb(int n)
{
    vi out;
    rep(i, 20)
    {
        if (n % 2)
            out.eb(i);
        n >>= 1;
    }
    return out;
}
vi dp(1 << 19, -1);

int func(int mask)
{
    if (dp[mask] != -1)
        return dp[mask];

    int ans = 0;
    rep(i, 19)
    {
        if (subset(itm(i), mask))
            ans = max(1 ^ func(set_minus(mask, itm(i))), ans);
        if (i < 3)
        {
            if (subset(itm(i) | itm(i + 4), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 4))), ans);
        }
        else if (i < 7)
        {
            if (subset((itm(i) | itm(i + 5)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 5))), ans);
        }
        else if (i < 11)
        {
            if (subset((itm(i) | itm(i + 5)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 5))), ans);
        }
        else if (i > 11 and i < 15)
        {
            if (subset((itm(i) | itm(i + 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 4))), ans);
        }

        if (i < 3)
        {
            if (subset((itm(i) | itm(i + 3)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 3))), ans);
        }
        else if (i < 7)
        {
            if (subset((itm(i) | itm(i + 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 4))), ans);
        }
        else if (i > 7 and i < 12)
        {
            if (subset((itm(i) | itm(i + 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 4))), ans);
        }
        else if (i > 12 and i < 16)
        {
            if (subset((itm(i) | itm(i + 3)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 3))), ans);
        }

        if (i > 2 and i < 6)
        {
            if (subset((itm(i) | itm(i + 4) | itm(i - 3)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 4) | itm(i - 3))), ans);
            if (subset((itm(i + 4) | itm(i - 3)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i + 4) | itm(i - 3))), ans);
        }
        else if (i > 7 and i < 11)
        {
            if (subset((itm(i) | itm(i + 4) | itm(i - 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 4) | itm(i - 4))), ans);
            if (subset((itm(i + 4) | itm(i - 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i + 4) | itm(i - 4))), ans);
        }
        else if (i > 12 and i < 16)
        {
            if (subset((itm(i) | itm(i + 3) | itm(i - 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 3) | itm(i - 4))), ans);
            if (subset((itm(i + 3) | itm(i - 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i + 3) | itm(i - 4))), ans);
        }

        if (i > 3 and i < 7)
        {
            if (subset((itm(i) | itm(i + 5) | itm(i - 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 5) | itm(i - 4))), ans);
            if (subset((itm(i + 5) | itm(i - 4)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i + 5) | itm(i - 4))), ans);
        }
        else if (i > 7 and i < 11)
        {
            if (subset((itm(i) | itm(i + 5) | itm(i - 5)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 5) | itm(i - 5))), ans);
            if (subset((itm(i + 5) | itm(i - 5)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i + 5) | itm(i - 5))), ans);
        }
        else if (i > 11 and i < 15)
        {
            if (subset((itm(i) | itm(i + 4) | itm(i - 5)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 4) | itm(i - 5))), ans);
            if (subset((itm(i + 4) | itm(i - 5)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i + 4) | itm(i - 5))), ans);
        }

        if (i < 2 or (i > 2 and i < 6) or (i > 6 and i < 11) or (i > 11 and i < 15) or (i > 15 and i < 18))
        {
            if (subset((itm(i) | itm(i + 1)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i + 1))), ans);
        }

        if ((i == 1) or (i > 3 and i < 6) or (i > 7 and i < 11) or (i > 12 and i < 15) or (i == 17))
        {
            if (subset((itm(i) | itm(i + 1) | itm(i - 1)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i) | itm(i - 1) | itm(i + 1))), ans);
            if (subset((itm(i + 1) | itm(i - 1)), mask))
                ans = max(1 ^ func(set_minus(mask, itm(i - 1) | itm(i + 1))), ans);
        }
    }
    return dp[mask] = ans;
}

int main()
{
    vector<string> names = {"Lillebror", "Karlsson"};
    dp[0] = 0;
    int mask = 0;
    char c;
    rep(k, 19)
    {
        cin >> c;

        if (c != '.')
        {
            mask |= (1 << k);
        }
    }
    cout << names[func(mask)] << '\n';
}