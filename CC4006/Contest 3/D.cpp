#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b - 1; i >= (int)a; i--)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

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
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

class UnionFind
{
    vi p, rank;
    vector<ll> setSize;

  public:
    UnionFind(int n)
    {
        rank.assign(n, 0);
        setSize.assign(n, 0);
        p.resize(n);
        rep(i, n) p[i] = i;
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void addSize(int i, ll w)
    {
        setSize[findSet(i)] += w;
    }
    void UnionSet(int i, int j)
    {
        if (not isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    ll sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> elements(n);
    vi permutations(n);
    rep(i, n)
    {
        cin >> elements[i];
    }
    rep(i, n)
    {
        cin >> permutations[i];
        permutations[i]--;
    }
    UnionFind U(n);

    vi in(n, 0);
    vector<ll> ans(n);
    vi dirs = {-1, 1};

    invrep(i, 1, n)
    {
        int j = permutations[i];
        U.addSize(j, elements[j]);
        for (auto dir : dirs)
        {
            int k = j + dir;
            if (0 <= k and k < n)
                if (in[k])
                    U.UnionSet(j, k);
        }
        in[j] = 1;
        ans[i - 1] = max(ans[i], U.sizeOfSet(j));
    }

    rep(i, n)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}