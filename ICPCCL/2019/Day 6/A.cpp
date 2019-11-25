#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
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

#define debugx(x) //cerr << #x << ": " << x << endl
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
#define debugmp(m) //\
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
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

int dijsktra(wgraph g, int start, int end, vi &marked)
{
    int n = g.size();
    vi cost(n, 1e9); //~INT_MAX/2
    priority_queue<par, vp, greater<par>> q;

    q.emplace(0, start);
    cost[start] = 0;
    while (not q.empty())
    {
        int u = q.top().second, w = q.top().first;
        q.pop();

        // we skip all nodes in the q that we have discovered before at a lower cost
        if (cost[u] < w)
            continue;

        for (auto v : g[u])
        {
            if (cost[v.second] > v.first + w and (!marked[v.second] or v.second == end))
            {
                cost[v.second] = v.first + w;
                q.emplace(cost[v.second], v.second);
            }
        }
    }

    return cost[end];
}

int main()
{
    int T;
    cin >> T;
    int n, m;
    while (T--)
    {
        debugx(m);
        debugx(n);
        cin >> m >> n;
        wgraph g((n + 4) * (m + 4));
        int directions[] = {(m + 4) * 2 + 1, (m + 4) * 2 - 1, (m + 4) - 2, (m + 4) + 2, -(m + 4) - 2, -(m + 4) + 2, -(m + 4) * 2 - 1, -(m + 4) * 2 + 1};
        rep(i, m) rep(j, n)
        {
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 1) + i + 1);
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 1) + i + 2);
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 1) + i + 3);
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 2) + i + 1);
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 2) + i + 3);
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 3) + i + 1);
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 3) + i + 2);
            g[(m + 4) * (j + 2) + i + 2].eb(1, (m + 4) * (j + 3) + i + 3);
        }
        vi marked((n + 4) * (m + 4), 0);
        int start, end;
        rep(i, m)
        {
            string s;
            cin >> s;
            debugx(s);
            rep(j, n)
            {
                if (s[j] == 'A')
                    start = (m + 4) * (j + 2) + i + 2;
                if (s[j] == 'B')
                    end = (m + 4) * (j + 2) + i + 2;
                if (s[j] == 'Z')
                {
                    marked[(m + 4) * (j + 2) + i + 2] = 1;
                    rep(k, 8)
                    {
                        marked[(m + 4) * (j + 2) + i + 2 + directions[k]] = 1;
                    }
                }
            }
        }
        int res = dijsktra(g, start, end, marked);
        if (res == 1e9)
            cout << "King Peter, you can't go now!\n";
        else
        {
            cout << "Minimal possible length of a trip is " << res << '\n';
        }
    }
}