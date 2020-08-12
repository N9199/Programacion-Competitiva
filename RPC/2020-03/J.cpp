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

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) //cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v) //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m) //          \
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
#define int ll
struct FenwickTree
{
    vector<int> FT;
    FenwickTree(int N) { FT.resize(N + 1, 0); }

    int query(int i)
    {
        ll ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j) { return query(j) - query(i - 1); }

    void update(int i, ll v)
    {
        int s = query(i, i); // Sets range to v?
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v;
    }

    // Queries puntuales, Updates por rango
    void update(int i, int j, ll v)
    {
        update(i, v);
        update(j + 1, -v);
    }

    void debug()
    {
        rep(i, FT.size() - 1) cerr << query(i + 1) << ' ';
        cerr << endl;
    }
};

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi p(n - 1);
    int M;
    cin >> M;
    rep(i, n - 1) cin >> p[i];
    sort(p.begin(), p.end());
    FenwickTree FT(n - 1);
    rep(i, n - 1)
    {
        FT.update(i + 1, i + 1, p[i]);
    }

    int ans = 0;
    ll last = FT.query(n - 1);
    //FT.debug();
    while (last > 0 and M >= last)
    {
        debugx("IT");
        debugx(ii(M, last));
        last = FT.query(n - 1);
        int left = 1, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (FT.query(mid) >= last)
                right = mid;
            else
                left = mid + 1;
        }
        debugx(left);

        if (left < n - 1)
        {
            FT.update((left + n) / 2, n - 1, 1);
        }
        int temp = (left > 1) ? FT.query(left - 1) : 0;
        ans += (last - temp);
        FT.update(left, n - 1, temp - last);
        M -= last - temp;
        debugx(temp - last);
        debugx(M);
        debugx(ans);
        temp = FT.query(1);
        FT.update(1, n - 1, -temp);
        //FT.debug();
        M -= temp;
    }
    if (M)
        ans += 2 * M;
    debugx(M);
    cout << ans << '\n';
}