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
const ll mod = 1e9 + 7;

struct Node
{
    int v;
    Node() { v = 0; } // neutro
    Node(int v) : v(v % mod) {}
    Node(const Node &a, const Node &b) { v = (a.v + b.v) % mod; }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST
{
    vector<node> t;
    int n;

    ST(vector<node> &arr, int N) : n(N), t(N * 2)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
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
    int k, l;
    cin >> k >> l;
    graph T(k, vi(k));
    rep(i, k) rep(j, k) cin >> T[i][j];
    vector<Node> a(k, 1);
    ST<Node> st1(a, k);
    ST<Node> st2(a, k);
    int n;
    cin >> n;
    vi p(n - 1);
    rep(i, n - 1) cin >> p[i];
    invrep(j, 0, n - 1)
    {
        rep(i, k)
        {
            int left = lower_bound(T[i].begin(), T[i].end(), p[j] - l) - T[i].begin();
            int right = upper_bound(T[i].begin(), T[i].end(), p[j] + l) - T[i].begin();
            //debugx(i);
            //debugx(ii(left, right));
            //debugx(st1.query(left, right).v);
            st2.set(i, st1.query(left, right));
        }
        swap(st1, st2);
        //debugx("");
    }
    ll out = st1.query(0, k).v;
    cout << out << '\n';
}