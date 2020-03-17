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
#define invrep(i, a, n) for (int i = n; i >= (int)a; --i)
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vi p(m + 1);
        rep(i, m)
        {
            cin >> p[i];
            p[i]--;
        }
        p[m] = n - 1;
        vi ans(26);
        graph acc(n, vi(26));
        rep(i, n)
        {
            if (i > 0)
                rep(j, 26)
                    acc[i][j] = acc[i - 1][j];
            acc[i][s[i] - 'a'] += 1;
        }
        rep(i, m + 1) rep(j, 26)
            ans[j] += acc[p[i]][j];

        rep(i, 26) cout << ans[i] << ' ';
        cout << '\n';
    }
}