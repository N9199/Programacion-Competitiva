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

vll dp;

ll func(int u, wgraph &g)
{
    if (dp[u] != -1)
        return dp[u];
    if (u == 0)
        return dp[u] = 0;

    ll ans = 1e9;
    for (auto v : g[u])
    {
        ans = min(ans, func(v.first, g) + v.second);
    }
    return dp[u] = ans;
}

// Range Sum Query
struct rsum
{
    int value;
    rsum() { value = 0; }
    rsum(int x) { value = x; }
    rsum(const rsum &a, const rsum &b) { value = a.value + b.value; }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }

    // 0-indexed
    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = node(t[p], t[p ^ 1]);
    }

    // inclusive exclusive, 0-indexed
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansl = node(ansl, t[l++]);
            if (r & 1)
                ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int main()
{
    int n;
    cin >> n;
    vi a(n + 2);
    priority_queue<ii> q;
    a[n + 1] = n + 1;
    q.emplace(n + 1, n + 1);
    rep(i, n)
    {
        cin >> a[i + 1];
        q.emplace(a[i + 1], i + 1);
    }
    vi p(n + 2);
    rep(i, n) cin >> p[i + 1];
    vector<rsum> temp(n + 2);
    ST<rsum> st(temp);
    int m;
    cin >> m;
    vi b(m + 2);
    b[m + 1] = n + 1;
    rep(i, m) { cin >> b[i + 1]; }
    rep(i, m + 1) if (b[i + 1] <= b[i])
    {
        cout << "NO\n";
        return 0;
    }
    uset<int> bs;
    bs.insert(b.begin(), b.end());
    vii nums;
    nums.reserve(n);
    rep(i, n + 2) if (bs.find(a[i]) != bs.end()) nums.eb(a[i], i);
    nums.shrink_to_fit();
    sort(nums.begin(), nums.end());
    debugv(nums);
    wgraph g(nums.size());
    dp.assign(nums.size(), -1);
    invrep(i, 1, nums.size())
    {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left < right)
        {
            mid = (left + right + 1) / 2;
            if (nums[mid].first < nums[i].first and nums[mid].second < nums[i].second)
                left = mid;
            else
                right = mid - 1;
        }
        int last = (right + left + 1) / 2;
        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= ii(nums[last].first, 0))
                right = mid;
            else
                left = mid + 1;
        }
        int first = (left + right) / 2;
        while (!q.empty() and q.top().first > nums[first].first)
        {
            st.set_point(q.top().second, rsum(b[q.top().second]).value);
            q.pop();
        }
        repx(j, first, last + 1) g[i].eb(j, st.query(nums[j].second, i).value);
    }
    cout << func(nums.size() - 1, g) << '\n';
}