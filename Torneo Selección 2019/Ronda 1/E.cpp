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

// Or LLONG_MAX for ll
#define INF INT_MAX

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m)                                  \
    cerr << #m << ":" << endl;                     \
    for (auto it = m.begin(); it != m.end(); it++) \
    {                                              \
        cerr << distance(m.begin(), it) << ":";    \
        for (auto e : *it)                         \
            cerr << " " << e;                      \
        cerr << endl;                              \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, " ")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

int main()
{
    ll xb, yb;
    cin >> xb >> yb;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2)
        swap(x1, x2);

    if (y1 > y2)
        swap(y1, y2);

    assert(x1 <= x2);
    assert(y1 <= y2);

    if (gcd(xb, yb) == 1)
        cout << "Yes\n";
    else
    {
        ll g = gcd(xb, yb);
        if (xb / g >= x1 and yb / g >= y1)
        {
            if (xb / g * (g - 1) <= x2 and yb / g * (g - 1) <= y2)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
                ll left = 1, right = g - 1;
                ll mid;
                while (left < right)
                {
                    mid = (left + right) / 2;
                    if (xb / g * mid <= x2 and yb / g * mid <= y2)
                        left = mid + 1;
                    else
                        right = mid;
                }
                mid = (left + right) / 2; //Was missing this line$$
                cout << xb / g * mid << ' ' << yb / g * mid << '\n';
            }
        }
        else
        {
            cout << "No\n";
            cout << xb / g << " " << yb / g << '\n';
        }
    }
}