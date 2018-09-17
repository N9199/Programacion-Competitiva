#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v) \
    //cerr << #v << ":";                          \
    rep(i, (int)v.size()) cerr << ", " << v[i]; \
    cerr << endl
#define debugm(m) \
    //cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) \
    //cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

vi primes;

void sieve()
{
    int n = 3e3;

    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);
}

int main()
{
    int n;
    cin >> n;
    graph g(n, vi(n, -1));
    int i = 0;
    int x = -1, y = 0;
    int dx = 1, dy = 0;
    sieve();
    while (g[y + dy][x + dx] == -1)
    {
        x += dx;
        y += dy;
        g[y][x] = primes[i++];

        if ((x == n - 1 or g[y][x + 1] != -1) and dx == 1)
        {
            dx = 0;
            dy = 1;
        }
        else if ((y == n - 1 or g[y + 1][x] != -1) and dy == 1)
        {
            dx = -1;
            dy = 0;
        }
        else if ((x == 0 or g[y][x - 1] != -1) and dx == -1)
        {
            dx = 0;
            dy = -1;
        }
        else if ((y == 0 or g[y - 1][x] != -1) and dy == -1)
        {
            dx = 1;
            dy = 0;
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}