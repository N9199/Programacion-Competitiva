#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> graph;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))

#define gcd __gcd

#define INF INT_MAX

#define umap unordered_map
#define uset unordered_set

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                         \
    cerr << #m << endl;                                                    \
    rep(i, (int)m.size())                                                  \
    {                                                                      \
        cerr << i << ":";                                                  \
        rep(j, (int)m[i].size())                                           \
        {                                                                  \
            cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        }                                                                  \
        cerr << endl;                                                      \
    }
int h, w;
vii d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool bfs(graph &g, graph &m)
{
    graph visited(h, vi(w, 1));
    queue<ii> q;
    q.emplace(0, 0);
    visited[0][0] = 0;
    if (g[0][0] != m[0][0])
        return false;
    while (not q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto e : d)
        {
            if (u.first + e.first > -1 and u.first + e.first < h and u.second + e.second > -1 and u.second + e.second < w)
            {
                if (visited[u.first + e.first][u.second + e.second])
                {
                    if (g[u.first + e.first][u.second + e.second] != m[u.first + e.first][u.second + e.second])
                    {
                        return false;
                    }
                    q.emplace(u.first + e.first, u.second + e.second);
                    visited[u.first + e.first][u.second + e.second] = 0;
                }
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cin >> h >> w;
    if (h < 3 or w < 3)
    {
        cout << "NO\n";
        return 0;
    }
    graph m(h, vi(w));

    bool flag = false;
    rep(i, h) rep(j, w)
    {
        char c;
        cin >> c;
        if (c == '*')
        {
            flag = true;
            m[i][j]++;
        }
    }
    if (not flag)
    {
        cout << "NO\n";
        return 0;
    }
    graph g(h, vi(w));
    repx(i, 1, h - 1) repx(j, 1, w - 1)
    {
        if (m[i][j])
        {
            flag = true;
            for (auto e : d)
            {
                if (not m[i + e.first][j + e.second])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                g[i][j] = 1;
                for (auto e : d)
                {
                    int di = 0;
                    int dj = 0;
                    while (i + di < h and i + di > -1 and j + dj < w and j + dj > -1)
                    {
                        if (m[i + di][j + dj] == 0)
                            break;
                        g[i + di][j + dj] = 1;
                        di += e.first;
                        dj += e.second;
                    }
                }
                goto end;
            }
        }
    }
end:
    //debugm(g);
    //debugm(m);

    if (bfs(g, m))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
