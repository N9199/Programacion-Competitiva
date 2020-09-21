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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    priority_queue<par> q;
    set<int> s;
    rep(i, n)
    {
        cin >> a[i];
        q.emplace(a[i], i);
        s.emplace(i);
    }
    string ans(n, '0');
    int x = 0;
    while (!q.empty() and !s.empty())
    {
        while (s.find(q.top().second) == s.end())
            q.pop();
        par curr = q.top();
        q.pop();
        vi team;
        auto it = s.find(curr.second);
        rep(_, k + 1)
        {
            team.pb(*it);
            if (it == s.begin())
                break;
            it--;
        }
        it = next(s.find(curr.second));
        rep(_, k)
        {
            if (it == s.end())
                break;
            team.pb(*it);
            it++;
        }
        for (auto id : team)
        {
            s.erase(id);
            ans[id] = '1' + x;
        }
        x ^= 1;
    }
    rep(i, n) cout << ans[i];
    cout << '\n';
}
