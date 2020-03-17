
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
//Only for iterables of ints
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> ai;
    set<int> s;

    while (s.size() < n - k + 1)
    {
        cout << "? ";
        int c = 0;
        rep(i, n)
        {
            if (s.find(i) == s.end())
            {
                cout << i + 1 << ' ';
                c++;
                if (c == k)
                    break;
            }
        }
        cout << endl;
        int pos, a;
        cin >> pos >> a;
        s.emplace(pos - 1);
        ai.emplace(a);
    }
    int c = 0;
    cout << "? ";
    if (s.size() < k)
    {
        rep(i, n)
        {
            if (s.find(i) == s.end())
            {
                cout << i + 1 << ' ';
                c++;
                break;
            }
        }
    }

    for (auto e : s)
    {
        cout << e + 1 << ' ';
        c++;
        if (c == k)
            break;
    }
    cout << endl;
    int pos, a;
    cin >> pos >> a;
    int d = distance(ai.begin(), ai.find(a));
    cout << "! " << d + 1 << endl;
}