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

int main()
{
    int n, m;
    cin >> n >> m;
    vii points(m);
    rep(i, m)
    {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end(), [](ii &a, ii &b) {
        return tie(a) < tie(b);
    });
    debugv(points);
    int x = 1, y = 1;
    int i = 0;
    while (y != n and i < m)
    {
        if (points[i].first != x)
            y = n;
        else
        {
            int x2 = x + 1, y2 = points[i].second - 1;
            int j = i, k = m - 1;
            bool flag = false;
            while (j < k)
            {
                int mid = (i + j) / 2;
                if (points[mid].first < x2)
                    j = mid;
                else if (points[mid].first > x2)
                    k = mid;
                else if (points[mid].second < y2)
                    j = mid;
                else if (points[mid].second > y2)
                    k = mid;
                else
                {
                    x++;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                j = i, k = m - 1;
                
            }
        }
    }
    if (y == n)
        cout << 2 * (n - 1) << '\n';
    else
        cout << -1 << '\n';
}