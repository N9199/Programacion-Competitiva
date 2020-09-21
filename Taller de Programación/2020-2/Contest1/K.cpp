#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

#define debugx(x) //cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

struct p
{
    int h, w, i;
    p() {}
    p(int h, int w, int i) : h(h), w(w), i(i) {}
    bool operator<(const p &o) const { return tie(w, h) < tie(o.w, o.h); }
};

ostream &operator<<(ostream &os, const p &o)
{
    os << '(' << o.h << ',' << o.w << ',' << o.i << ')';
    return os;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rep(_, n)
    {
        int m, q;
        cin >> m >> q;
        vector<p> in(m);
        unordered_map<int, vi> g;
        unordered_map<int, int> boss;
        rep(i, m) cin >> in[i].i >> in[i].w >> in[i].h;
        sort(in.begin(), in.end());
        debugv(in);
        rep(_, q) cin >> m;
    }
}