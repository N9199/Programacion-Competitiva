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

#define debugx(x) cerr << #x << ": " << x << endl

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

#define ff first
#define ss second


int h, w, r, s;
graph g;
vp pos;
vi dp;
par start, fin;
inline bool in(int y, int x) { return x >= 0 and x < w and y >= 0 and y < h; }
void make_graph(graph &m)
{
    int c = 0;
    start = par(h - 1, w - 1);
    fin = par(0, 0);
    graph m2(h, vi(w, -1));
    rep(i, h) rep(j, w) if (m[i][j])
    {
        debugx(par(i, j));
        start = min(start, par(i, j));
        fin = max(fin, par(i, j));
        pos.eb(i, j);
        m2[i][j] = c++;
    }
    debugm(m2);
    g.resize(c);
    dp.assign(c, -1);
    rep(i, c) repx(dy, -3, 4) repx(dx, -3, 4) if (in(pos[i].first + dy, pos[i].second + dx) and m[pos[i].first + dy][pos[i].second + dx] and dy * dy + dx * dx <= r * r)
    {
        debugx(par(pos[i].first + dy, pos[i].second + dx));
        debugx(m2[pos[i].first + dy][pos[i].second + dx]);
        g[i].eb(m2[pos[i].first + dy][pos[i].second + dx]);
    }
    debugm(g);
}

int main()
{
    cin >> h >> w >> r >> s;
    graph m(h, vi(w));
    char c;
    rep(i, h) rep(j, w)
    {
        cin >> c;
        if (c != '.')
            m[i][j] = c - '0';
    }
    debugm(m);
    make_graph(m);
}
