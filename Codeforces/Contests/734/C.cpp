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

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        graph g(n, vi(6));
        rep(i, n)
        {
            string s;
            cin >> s;
            for (auto &c : s)
                g[i][c - 'a']++;
            g[i][5] = s.size();
        }
        int ans = 0;
        rep(j, 5)
        {
            int temp = 0;
            bool flag = false;
            sort(g.rbegin(), g.rend(), [&](const vi &a, const vi &b) -> bool
                 { return a[j] < b[j]; });
            //debugm(g);
            int c1 = 0, c2 = 0;
            rep(i, n)
            {
                if (c1 - c2 >= g[i][5] - 2 * g[i][j])
                {
                    temp++;
                    c1 += g[i][j];
                    c2 += g[i][5] - g[i][j];
                }
                flag |= g[i][5] < 2 * g[i][j];
            }
            //debugx(temp);
            //debugx(j);
            //debugx(flag);
            if (c1 == c2)
                temp--;
            if (flag)
                ans = max(temp, ans);
        }
        cout << ans << '\n';
    }
}