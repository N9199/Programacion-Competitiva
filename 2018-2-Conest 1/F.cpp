#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long intt;
typedef vector<intt> vi;
typedef pair<intt, intt> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<intt> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

intt area(par &A, par &B, par &C)
{
    return abs((B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first));
}

int main()
{
    int n;
    while (cin >> n)
    {
        vp vert(n + 4);
        rep(i, n) cin >> vert[i].first >> vert[i].second;
        vert[n] = vert[0];
        vert[n + 1] = vert[1];
        vert[n + 2] = vert[2];
        vert[n + 3] = vert[3];
        intt total = 0;
        repx(i, 1, n - 1) total += area(vert[0], vert[i], vert[i + 1]);
        intt here = 0;
        int i = 0;
        int j = 1;
        intt best = 0;
        while (i < n + 1)
        {
            while (here < total - here)
            {
                here += area(vert[i], vert[j], vert[j + 1]);
                j %= n;
                j++;
            }
            intt other = here - area(vert[i], vert[j], vert[j - 1]);
            best = max(best, min(here, total - other));
            here -= area(vert[i], vert[i + 1], vert[j]);
            i++;
        }
        cout << best << " " << total - best << endl;
    }
}