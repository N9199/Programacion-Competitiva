#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> graph;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))

#define gcd __gcd

#define INF INT_MAX

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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    char c1, c2;
    int x1, y1, x2, y2;
    rep(_, n)
    {
        cin >> c1 >> x1 >> c2 >> x2;
        x1--;
        x2--;
        y1 = c1 - 'A';
        y2 = c2 - 'A';
        if ((x1 + y1) % 2 != (x2 + y2) % 2)
        {
            cout << "Impossible\n";
            continue;
        }
        if (x1 == x2 and y1 == y2)
        {
            cout << "1 " << (char)(y1 + 'A') << ' ' << x1 + 1 << '\n';
            continue;
        }
        if (abs(x1 - x2) == abs(y1 - y2))
        {
            cout << "1 " << (char)(y1 + 'A') << ' ' << x1 + 1 << ' ' << (char)(y2 + 'A') << ' ' << x2 + 1 << '\n';
            continue;
        }
        cout << "2 ";
        int r1 = x1 - y1, r2 = x2 - y2;
        int x = (abs(r1) + abs(r2));
        debugx(x);
        vector<ii> d = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        cout << (char)(y1 + 'A') << ' ' << x1 + 1 << ' ';
        rep(i, 4)
        {
            rep(j, x)
            {
                if (x1 + d[i].first * j > -1 and x1 + d[i].first * j < 8 and y1 + d[i].second * j > -1 and y1 + d[i].second * j < 8 and abs(x1 + d[i].first * j - x2) + abs(y1 + d[i].first * j - y2) <= abs(x1 - x2) + abs(y1 - y2) and abs(x1 + d[i].first * j - x2) == abs(y1 + d[i].first * j - y2))
                {
                    cout << (char)(y1 + d[i].second * j + 'A') << " " << x1 + d[i].first * j + 1 << ' ';
                    goto end;
                }
            }
        }
    end:
        cout << (char)(y2 + 'A') << ' ' << x2 + 1 << '\n';
    }
    return 0;
}
