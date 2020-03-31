#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> par;
typedef vector<ll> vi;
typedef vector<ll> vll;

typedef vector<vi> graph;
typedef vector<vll> vvll;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

struct camino
{
    camino(int a, ll b, ll c) : a(a), length(b), cost(c) {}
    int a;
    ll length;
    ll cost;
    //Used for sorting in the priority_queue (max_heap)
    bool operator<(const camino &x) const
    {
        if (length != x.length)
            return length >= x.length;

        if (cost != x.cost)
            return cost >= x.cost;
        return a > x.a;
    }
};

typedef vector<camino> vc;
typedef vector<vc> wgraph;

int main()
{
    //Read input and set stuff up
    ll total_cost = 0;
    ll n, m;
    cin >> n >> m;
    wgraph g(n);
    vi dist(n, 1e18);
    vi cost(n, -1);
    rep(i, m)
    {
        ll a, b, l, c;
        cin >> a >> b >> l >> c;
        a--;
        b--;
        g[a].eb(b, l, c);
        g[b].eb(a, l, c);
    }

    //Dijsktra
    dist[0] = 0;
    cost[0] = 0;
    priority_queue<camino> q;
    q.emplace(0, 0, 0);
    while (!q.empty())
    {
        camino u = q.top();
        q.pop();
        for (auto v : g[u.a])
        {
            //If there's a shortest path take it
            if (dist[v.a] > dist[u.a] + v.length)
            {
                dist[v.a] = dist[u.a] + v.length;
                cost[v.a] = v.cost;
                q.emplace(v.a, dist[v.a], v.cost);
                continue;
            }
            //If there's a path that's as short, but cheaper take it
            if (dist[v.a] == dist[u.a] + v.length && cost[v.a] > v.cost)
            {
                cost[v.a] = v.cost;
                q.emplace(v.a, dist[v.a], v.cost);
                continue;
            }
        }
    }
    // Total cost is the cost to get to every node
    for (auto c : cost)
    {
        total_cost += c;
    }
    cout << total_cost << '\n';
}