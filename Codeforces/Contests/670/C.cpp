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
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)
#define pb push_back
#define eb emplace_back

#define debugx(x) // cerr << #x << ": " << x << endl

#define debugv(v) //       \
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
int n;
vi sz;
graph g;
void get_size(int u, int prev)
{
    //debugx(u);
    sz[u] = 1;
    for (auto v : g[u])
        if (v != prev)
        {
            get_size(v, u);
            sz[u] += sz[v];
        }
}
// get_size(root,-1)
vector<par> centroids;
void find_centroids(int u, int prev)
{
    bool is_centroid = true;
    for (auto v : g[u])
        if (v != prev)
        {
            find_centroids(v, u);
            if (sz[v] > n / 2)
                is_centroid = false;
        }
    if (n - sz[u] > n / 2)
        is_centroid = false;
    if (is_centroid)
        centroids.eb(u, prev);
}

int main()
{
    int t;
    cin >> t;
    rep(_, t)
    {
        cin >> n;
        g.clear();
        g.resize(n);
        sz.assign(n, 0);
        int x, y;
        centroids.clear();
        rep(__, n - 1)
        {
            cin >> x >> y;
            x--;
            y--;
            g[x].eb(y);
            g[y].eb(x);
        }
        debugx("Input read");
        get_size(0, -1);
        find_centroids(0, -1);
        debugx("Centroids found");
        debugv(centroids);
        if (centroids.size() > 1)
        {
            debugx("At least two centroids");
            rep(i, 2)
            {
                auto u = centroids[i];
                for (auto v : g[u.first])
                    if (v != u.second)
                    {
                        if (centroids[1 - i].first != v)
                        {
                            cout << v + 1 << ' ' << u.first + 1 << '\n';
                            cout << v + 1 << ' ' << centroids[1 - i].first + 1 << '\n';
                            //par(v, u.first)
                            goto end;
                        }
                    }
                    else if (centroids[1 - i].first != u.first and centroids[1 - i].first != u.second)
                    {
                        cout << u.second + 1 << ' ' << u.first + 1 << '\n';
                        cout << u.second + 1 << ' ' << centroids[1 - i].first + 1 << '\n';
                        //u
                        goto end;
                    }
            }
        }
        else
        {
            debugx("One Centroid");
            cout << 1 << ' ' << g[0][0] + 1 << '\n';
            cout << 1 << ' ' << g[0][0] + 1 << '\n';
        }
    end:
        continue;
    }
}