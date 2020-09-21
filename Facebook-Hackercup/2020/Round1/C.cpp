#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, ll> par;
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
    os << p.first << ' ' << p.second;
    return os;
}

int DP[(int)1e6];

int func(int u, int v, graph &g, bool f, vi &vis)
{
    if (DP[u] != -1)
        return DP[u];
    DP[u] = (g[u].size() == 1);
    for (auto w : g[u])
        if (w != v and (f or vis[w] != -1))
            DP[u] += func(w, u, g, f, vis);
    return DP[u];
}

void traverse(int u, int v, bool f, ll &ans, graph &g, vi &vis)
{
    debugx(u);
    debugx(ans);
    for (auto w : g[u])
        if (w != v and (f or vis[w] != -1))
        {
            int temp = func(u, v, g, f, vis);
            debugx(temp);
            ans += (g.size() - temp) * temp;
            traverse(w, u, f, ans, g, vis);
        }
}

void fill(int u, vi &vis, graph &g, par &ans)
{
    ans.first++;
    vis[u] = 1;
    for (auto v : g[u])
        if (vis[v] == -1)
            ans.second++;
        else if (!vis[v])
            fill(v, vis, g, ans);
}

int main()
{
    int t;
    cin >> t;
    rep(C, t)
    {
        debugx(C);
        int n, k;
        cin >> n >> k;
        memset(DP, -1, sizeof(DP));
        vi vis(n);
        graph g(n);
        char ca;
        rep(i, n)
        {
            cin >> ca;
            if (ca == '#')
                vis[i] = -1;
        }
        int a, b, c;
        ll v;
        vector<ll> E(n);
        repx(u, 1, k + 1)
        {
            cin >> v;
            E[u] = v;
            v--;
            g[u].eb(v);
            g[v].eb(u);
        }
        cin >> a >> b >> c;
        repx(u, k + 1, n)
        {
            E[u] = ((a * E[u - 2]) % u + (b * E[u - 1]) % u + c) % u;
            v = E[u];
            g[u].eb(v);
            g[v].eb(u);
            E[u]++;
        }
        debugv(E);
        debugm(g);
        c = 0;
        vp cc;
        cc.reserve(n);
        rep(u, n) if (vis[u] == 0)
        {
            cc.eb();
            fill(u, vis, g, cc[c]);
            debugv(vis);
            c++;
        }
        par ans = {0, 0};
        debugx(c);
        if (c == 0)
        {
            rep(u, n) if (g[u].size() == 1)
            {
                func(u, -1, g, true, vis);
                traverse(u, -1, true, ans.second, g, vis);
                break;
            }
        }
        else if (c == 1)
        {
            rep(u, n) if (vis[u] == 1)
            {
                bool temp = false;
                for (auto v : g[u])
                {
                    if (vis[v] == 1)
                    {
                        if (temp)
                        {
                            temp = false;
                            break;
                        }
                        else
                        {
                            temp = true;
                        }
                    }
                }
                if (temp)
                {
                    func(u, -1, g, false, vis);
                    traverse(u, -1, false, ans.second, g, vis);
                    debugx(cc[0]);
                    ans.first = cc[0].first * (cc[0].first - 1) / 2;
                    //ans.second = 0; //count ways to reconnect
                    break;
                }
            }
        }
        else
        {
            sort(cc.rbegin(), cc.rend());
            debugv(cc);
            ans.first = (cc[0].first + cc[1].first) * (cc[0].first + cc[1].first - 1) / 2;
            repx(i, 1, cc.size())
            {
                if (i > 1 and cc[i].first < cc[i - 1].first)
                    break;
                ans.second += cc[0].second * cc[i].first + cc[0].first * cc[i].second;
            }
        }
        cout << "Case #" << C + 1 << ": " << ans << '\n';
    }
}