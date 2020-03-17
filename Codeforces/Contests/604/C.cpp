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
#define debugm(m)             \
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
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
    int t;
    cin >> t;
    while (t--)
    {
        map<ll, ll> m;
        int n;
        cin >> n;
        int past = -1;
        rep(i, n)
        {
            int temp;
            cin >> temp;
            if (temp < past)
            {
                m[temp] += m[past];
            }
            past = temp;
            m[temp] += 1;
        }
        int temp = (n + n % 2) / 2;
        int b = 0, s = 0, g = 0;
        //debugv(m);
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second <= temp)
            {
                if (b == 0)
                {
                    b = it->second;
                    temp = (b - b % 3) / 3 - 1;
                }
                else if (g == 0)
                {
                    g = it->second;
                    while (2 * g >= s)
                    {
                        it--;
                        s = it->second;
                    }
                    if (s == b)
                    {
                        g == 0;
                    }
                    break;
                }
            }
        }
        if (g == 0)
        {
            cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
        }
        else
        {
            cout << g << ' ' << s - g << ' ' << b - s << '\n';
        }
    }
}