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

struct rmaxq
{
    int value;
    rmaxq() { value = INT_MIN; }
    rmaxq(int x) { value = x; }
    rmaxq(const rmaxq &a, const rmaxq &b) { value = max(a.value, b.value); }
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

int update(int i, int n, vi &right)
{
    if(i+1<n)
        return (right[i + 1] == i + 1) ? i + 1 : right[i + 1] = update(i + 1, n, right);
    return n;
}

int main()
{
    int t;
    cin >> t;
    rep(_, t)
    {
        int n;
        cin >> n;
        vii p(n);
        rep(i, n)
        {
            cin >> p[i].first;
            p[i].second = i;
        }
        vector<rmaxq> c(n);
        rep(i, n) c[i] = rmaxq(1);
        ST<rmaxq> m(c);
        vi right(n);
        rep(i, n) right[i] = i;
        bool flag = true;
        sort(p.begin(), p.end());
        rep(i, n)
        {
            //debugx(m.query(0, n).value);
            //debugx(m.query(p[i].second, p[i].second + 1).value);
            //debugx(p[i].first);
            if (m.query(p[i].second, p[i].second + 1).value >= m.query(0, n).value)
            {
                right[p[i].second] = update(p[i].second, n, right);
                if (right[p[i].second] < n)
                    m.set_point(right[p[i].second], rmaxq(m.query(right[p[i].second], right[p[i].second] + 1).value + m.query(p[i].second, p[i].second + 1).value));
                m.set_point(p[i].second, rmaxq(0));

            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}