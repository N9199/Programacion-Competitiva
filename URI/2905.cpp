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
#define debugm(m)             \
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

template <typename T1, typename T2>
istream &operator>>(istream &os, pair<T1, T2> &p)
{
    os >> p.first >> skipws >> p.second;
    return os;
}
#define double long double

vii trips;

vector<double> dp;
vector<double> discount = {1, 0.5, 0.25, 0.25, 0.25, 0.25};
double func(int trip)
{
    if (dp[trip] > -0.5)
        return dp[trip];
    if (trip == 0)
        return 0;
    double ans = 1e9;
    int time = 0;
    double temp = 0;
    rep(i, 6)
    {
        if (time >= 120)
            break;
        if (trip - i == 0)
            break;
        temp += discount[i] * trips[trip - i].second;
        ans = min(ans, temp + func(trip - i - 1));
        time += trips[trip - i].first;
    }
    return dp[trip] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(2);
    cerr.setf(ios::fixed);
    cerr.precision(2);
    int n;
    cin >> n;
    trips.resize(n + 1);
    rep(i, n)
    {
        cin >> trips[n - i];
    }
    dp.assign(n + 1, -1);
    //debugv(trips);
    //debugv(dp);
    cout << func(n) << '\n';
    //debugv(dp);
}