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
set<string> p2;
int dist(string a, string b) //a->b
{
    //debugx(a);
    //debugx(b);
    int out = 0;
    for (auto ita = a.begin(), itb = b.begin(); itb != b.end(); itb++, ita++, out++)
    {
        while (ita != a.end() and *ita != *itb)
            ita++;
        if (ita == a.end())
            break;
    }
    //debugx(out);
    //debugx(a.size() + b.size() - 2 * out);
    return a.size() + b.size() - 2 * out;
}

int main(int argc, char const *argv[])
{
    ll n = 1;
    rep(_, 62)
    {
        p2.emplace(to_string(n));
        n *= 2;
    }
    int t;
    cin >> t;
    rep(_, t)
    {
        string n;
        cin >> n;
        int out = 14;
        for (auto e : p2)
            out = min(out, dist(n, e));
        cout << out << '\n';
    }
    return 0;
}
