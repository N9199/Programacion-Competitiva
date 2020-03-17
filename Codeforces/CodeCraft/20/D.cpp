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
    for (auto &v : m)         \
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

vp dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<char> cdirs = {'U', 'L', 'D', 'R'};
map<par, char> toChar;
int n;
graph visited;
void bfs(vector<vector<char>> &ans, wgraph &M, par end)
{
    queue<par> q;
    q.emplace(end);
    while (!q.empty())
    {
        par u = q.front();

        q.pop();
        for (auto dir : dirs)
        {
            par v = {u.first + dir.first, u.second + dir.second};
            if (u.first + dir.first >= 0 and u.first + dir.first < n and u.second + dir.second >= 0 and u.second + dir.second < n and !visited[v.first][v.second] and M[v.first][v.second] == end)
            {
                visited[v.first][v.second] = 1;
                q.emplace(v);
                ans[v.first][v.second] = toChar[dir];
            }
        }
    }
}

void bfs2(vector<vector<char>> &ans, wgraph &M, par start)
{
    queue<par> q;
    q.emplace(start);
    while (!q.empty())
    {
        par u = q.front();

        q.pop();
        for (auto dir : dirs)
        {
            par v = {u.first + dir.first, u.second + dir.second};
            if (u.first + dir.first >= 0 and u.first + dir.first < n and u.second + dir.second >= 0 and u.second + dir.second < n and !visited[v.first][v.second])
            {
                visited[v.first][v.second] = 1;
                q.emplace(v);
                for (auto d : dirs)
                {
                    if (v.first + d.first >= 0 and v.first + d.first < n and v.second + d.second >= 0 and v.second + d.second < n and M[v.first + d.first][v.second + d.second] == M[v.first][v.second])
                        ans[v.first][v.second] = toChar[make_pair(-d.first, -d.second)];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    rep(i, 4) toChar[dirs[i]] = cdirs[i];
    cin >> n;
    wgraph M(n, vp(n));
    visited.assign(n, vi(n));
    rep(i, n) rep(j, n) cin >> M[i][j].first >> M[i][j].second;
    rep(i, n) rep(j, n) M[i][j].first--, M[i][j].second--;
    vector<vector<char>> ans(n, vector<char>(n));
    rep(i, n) rep(j, n) if (i == M[i][j].first and j == M[i][j].second)
    {
        ans[i][j] = 'X';
        visited[i][j] = 1;
    }
    rep(i, n) rep(j, n) if (M[i][j].first >= 0 and M[i][j] != M[M[i][j].first][M[i][j].second])
    {
        cout << "INVALID\n";
        return 0;
    }
    rep(i, n) rep(j, n) if (M[i][j].first >= 0) bfs(ans, M, M[i][j]);
    rep(i, n) rep(j, n) bfs2(ans, M, {i, j});
    debugm(ans);
    rep(i, n) rep(j, n) if (ans[i][j] == 0)
    {
        cout << "INVALID\n";
        return 0;
    }
    cout << "VALID\n";
    rep(i, n)
    {
        rep(j, n) cout << ans[i][j];
        cout << '\n';
    }
}