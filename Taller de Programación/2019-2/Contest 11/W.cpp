#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vii> wgraph;
typedef vector<vi> graph;
typedef vector<vll> vvll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

struct edge
{
    int i, A, B;
    edge(int i, int A, int B) : i(i), A(A), B(B) {}
    double operator()(double t) { return A * t + B; }
};

vector<vector<edge>> g;
vector<double> dist;

double dijsktra(double t) // t: Time checked
{
    int start = 0;
    int n = g.size();
    dist.assign(g.size(), 1e10);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.emplace(0, start);
    dist[start] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        double w = q.top().first;
        q.pop();
        if (w > dist[u])
            continue;
        if (u == n - 1)
            return dist[u];
        for (auto v : g[u])
        {
            if (v(t) + w < dist[v.i])
            {
                dist[v.i] = v(t) + w;
                q.emplace(dist[v.i], v.i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(5);
    int n, m;
    while (cin >> n >> m)
    {
        g.assign(n, vector<edge>());
        dist.assign(n, 1e10);
        rep(_, m)
        {
            int a, b, i, j;
            cin >> i >> j >> a >> b;
            i--, j--;
            g[i].eb(j, a, b);
            g[j].eb(i, a, b);
        }

        double left = 0, right = 24 * 60;
        double temp1 = 0, temp2 = 0;
        rep(_, 100)
        {

            double t1 = left + (right - left) / 3.0, t2 = right + (left - right) / 3.0;
            temp1 = dijsktra(t1);
            temp2 = dijsktra(t2);
            if (temp1 > temp2)
            {
                right = t2;
            }
            else
            {
                left = t1;
            }
        }
        cout << (temp1 + temp2) / 2 << '\n';
    }
}