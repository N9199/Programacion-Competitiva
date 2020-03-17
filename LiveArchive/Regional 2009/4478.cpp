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

graph minLU;
graph minLD;
graph minRD;
graph minRU;

graph maxLU;
graph maxLD;
graph maxRD;
graph maxRU;

graph vals;

void precompute()
{
    int n = vals.size(), m = vals[0].size();

    minLU = vals;
    minLD = vals;
    minRD = vals;
    minRU = vals;

    maxLU = vals;
    maxLD = vals;
    maxRD = vals;
    maxRU = vals;
    repx(i, 1, n)
    {
        minRD[i][0] = min(vals[i][0], minRD[i - 1][0]);
        minLD[n - 1 - i][0] = min(vals[n - 1 - i][0], minLD[n - i][0]);
        minRU[i][m - 1] = min(vals[i][m - 1], minRU[i - 1][m - 1]);
        minLU[n - 1 - i][m - 1] = min(vals[n - 1 - i][m - 1], minLU[n - i][m - 1]);

        maxRD[i][0] = max(vals[i][0], maxRD[i - 1][0]);
        maxLD[n - 1 - i][0] = max(vals[n - 1 - i][0], maxLD[n - i][0]);
        maxRU[i][m - 1] = max(vals[i][m - 1], maxRU[i - 1][m - 1]);
        maxLU[n - 1 - i][m - 1] = max(vals[n - 1 - i][m - 1], maxLU[n - i][m - 1]);
    }
    repx(j, 1, m)
    {
        minRD[0][j] = min(vals[0][j], minRD[0][j - 1]);
        minLD[n - 1][j] = min(vals[n - 1][j], minRD[n - 1][j - 1]);
        minRU[0][m - 1 - j] = min(vals[0][m - 1 - j], minRU[0][m - j]);
        minLU[n - 1][m - 1 - j] = min(vals[n - 1][m - 1 - j], minLU[n - 1][m - 1 - j]);

        maxRD[0][j] = max(vals[0][j], maxRD[0][j - 1]);
        maxLD[n - 1][j] = max(vals[n - 1][j], maxRD[n - 1][j - 1]);
        maxRU[0][m - 1 - j] = max(vals[0][m - 1 - j], maxRU[0][m - j]);
        maxLU[n - 1][m - 1 - j] = max(vals[n - 1][m - 1 - j], maxLU[n - 1][m - 1 - j]);
    }
    repx(i, 1, n) repx(j, 1, m)
    {
        minRD[i][j] = min({vals[i][j], minRD[i - 1][j], minRD[i][j - 1]});
        minLD[n - 1 - i][j] = min({vals[n - 1 - i][j], minLD[n - i][j], minLD[n - 1 - i][j - 1]});
        minRU[i][m - 1 - j] = min({vals[i][m - 1 - j], minRU[i - 1][m - 1 - j], minRU[i][m - j]});
        minLU[n - 1 - i][m - 1 - j] = min({vals[n - 1 - i][m - 1 - j], minLU[n - i][m - 1 - j], minLU[n - 1 - i][m - j]});

        maxRD[i][j] = max({vals[i][j], maxRD[i - 1][j], maxRD[i][j - 1]});
        maxLD[n - 1 - i][j] = max({vals[n - 1 - i][j], maxLD[n - i][j], maxLD[n - 1 - i][j - 1]});
        maxRU[i][m - 1 - j] = max({vals[i][m - 1 - j], maxRU[i - 1][m - 1 - j], maxRU[i][m - j]});
        maxLU[n - 1 - i][m - 1 - j] = max({vals[n - 1 - i][m - 1 - j], maxLU[n - i][m - 1 - j], maxLU[n - 1 - i][m - j]});
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vals.assign(n, vi(m));
    rep(i, n) rep(j, m) { cin >> vals[i][j]; }
    precompute();
    debugm(vals);
    debugm(minLD);
    //REDO use 4 dirs instead
}