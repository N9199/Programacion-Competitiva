#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
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
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int n, m, a, b;
vector<set<int>> g;

int main()
{
    cin >> n >> m;
    g.resize(n);
    rep(i, m)
    {
        cin >> a >> b;
        g[a - 1].insert(b - 1);
        g[b - 1].insert(a - 1);
    }

    int count = 0;
    bool out = false;
    vi marked(n, false);
    while (true)
    {
        vi arr;
        rep(i, n)
        {
            if (marked[i])
                continue;
            int size = 0;
            for (auto k : g[i])
                if (!marked[k])
                    size++;
            if (size == 1)
            {
                arr.pb(i);
                out = true;
            }
        }
        for (int i : arr)
            marked[i] = true;
        if (out)
        {
            out = false;
            count++;
        }
        else
            break;
    }

    cout << count << '\n';
}
