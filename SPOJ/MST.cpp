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

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

class UnionFind
{
    int n;
    int num_sets;
    vi p;
    vi size;
    vi rank;
    vp edges;

public:
    ll weight;
    UnionFind(int n) : n(n), num_sets(n)
    {
        p.resize(n);
        rep(i, n) p[i] = i;
        size.assign(n, 1);
        rank.assign(n, 0);
        weight = 0;
    }

    void unionSet(int u, int v, ll w)
    {
        if (!isSameSet(u, v))
        {
            weight += w;
            num_sets--;
            int x = findSet(u), y = findSet(v);
            if (rank[x] > rank[y])
            {
                p[y] = x;
                size[x] += size[y];
            }
            else
            {
                p[x] = y;
                size[y] += size[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }

    int findSet(int i)
    {
        return p[i] == i ? i : p[i] = findSet(p[i]);
    }

    bool isSameSet(int u, int v)
    {
        return findSet(u) == findSet(v);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<ll, par>> temp(m);
    rep(i, m)
    {
        cin >> temp[i].second.first >> temp[i].second.second >> temp[i].first;
        temp[i].second.first--;
        temp[i].second.second--;
    }
    sort(temp.begin(), temp.end());
    rep(i, m) uf.unionSet(temp[i].second.first, temp[i].second.second, temp[i].first);
    cout << uf.weight << '\n';
}