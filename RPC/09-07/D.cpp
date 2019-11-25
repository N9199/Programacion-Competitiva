#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; ++i)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << _p.first << ' ' << _p.second;
    return _os;
}

bool bfs(graph &g, int start, int end)
{
    int n = g.size();
    vi visited(n, 1);
    queue<int> q;

    q.emplace(start);
    visited[start] = 0;
    while (not q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (end == v)
                return true;
            if (visited[v])
            {
                q.emplace(v);
                visited[v] = 0;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph f(2 * n + 2 * m, vi());
    graph af(2 * n + 2 * m, vi());
    umap<string, int> stoi;
    int lastIndex = 0;
    rep(i, n)
    {
        string str1, str2;
        cin >> str1;
        rep(_, 4)
        {
            cin >> str2;
        }
        if (stoi.find(str1) == stoi.end())
        {
            stoi[str1] = lastIndex;
            lastIndex++;
        }
        if (stoi.find(str2) == stoi.end())
        {
            stoi[str2] = lastIndex;
            lastIndex++;
        }
        f[stoi[str1]].eb(stoi[str2]);
        af[stoi[str2]].eb(stoi[str1]);
    }
    rep(i, m)
    {
        string str1, str2;
        cin >> str1;
        rep(_, 4)
        {
            cin >> str2;
        }
        if (stoi.find(str1) == stoi.end())
        {
            stoi[str1] = lastIndex;
            lastIndex++;
        }
        if (stoi.find(str2) == stoi.end())
        {
            stoi[str2] = lastIndex;
            lastIndex++;
        }
        if (bfs(f, stoi[str1], stoi[str2]))
        {
            cout << "Fact\n";
        }
        else if (bfs(af, stoi[str1], stoi[str2]))
        {
            cout << "Alternative Fact\n";
        }
        else
        {
            cout << "Pants on Fire\n";
        }
    }
}