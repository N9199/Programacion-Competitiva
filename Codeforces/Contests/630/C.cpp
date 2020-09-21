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
#define debugx(x) //cerr << #x << ": " << x << endl
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

int main()
{
    int t;
    cin >> t;
    int n, k;
    string s;
    int ans;
    vector<umap<char, int>> m;
    rep(_, t)
    {
        cin >> n >> k;
        cin >> s;
        ans = 0;
        m.clear();
        m.resize(k);
        rep(i, k) rep(j, n / k) m[i][s[i + k * j]] += 1;
        rep(i, k / 2)
        {
            for (auto [key, value] : m[i])
                m[k - 1 - i][key] += value;
            auto temp = make_pair(0, ' ');
            for (auto [key, value] : m[k - 1 - i])
                temp = max(temp, make_pair(value, key));

            ans += 2 * (n / k) - temp.first;
        }
        if (k % 2)
        {
            auto temp = make_pair(0, ' ');
            for (auto [key, value] : m[k / 2])
                temp = max(temp, make_pair(value, key));
            ans += (n / k) - temp.first;
        }
        cout << ans << '\n';
    }
}