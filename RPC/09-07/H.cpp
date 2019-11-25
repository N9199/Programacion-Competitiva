#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, bool> par;
typedef pair<par, int> triple;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<par> vp;

const int mod = INT_MAX;
typedef unordered_map<int, triple> umap;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < b; i++)
#define invrep(i, a, b) for (int i = b; i-- > a;)

#define eb emplace_back

par dfs(vvi &tree, int source, int parent, int rat)
{
    if (source != parent)
    {
        bool found = false;
        if (source == rat)
            found = true;
        int val = 1;
        for (int i : tree[source])
        {
            if (i == parent)
                continue;
            par x = dfs(tree, i, source, rat);
            val = max(val, 1 + x.first);
            if (x.second)
                found = true;
        }
        return par(val, found);
    }
    else
    {
        int val = 0;
        for (int i : tree[source])
        {
            par x = dfs(tree, i, source, rat);
            if (x.second)
            {
                val = max(val, x.first);
            }
        }
        return par(val, 1);
    }
}

int main()
{
    int n, r, h, m;
    cin >> n >> r >> h >> m;
    r--;
    h--;
    m--;
    vvi tree(n);
    rep(_, n - 1)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        tree[i].eb(j);
        tree[j].eb(i);
    }
    cout << min(dfs(tree, h, h, r).first, dfs(tree, m, m, r).first) << endl;
}