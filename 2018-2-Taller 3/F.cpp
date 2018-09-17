#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> graph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugp(p) //cerr << #p << ": (" << p.first << ", " << p.second << ")" << endl
#define debugv(v) //         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
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

unordered_set<int> primes;

void get_primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.emplace(i);
}

graph create_spiral(int s)
{
    graph spiral(s, vi(s, -1));
    int x = (s - 1) / 2;
    int y = (s - 1) / 2;
    int delta = (s - 1) / 2;
    int dx = 1;
    int dy = 0;
    bool flag = false;
    int s_s = s * s;
    repx(i, 1, (s_s + 1))
    {
        pair<int, int> pos(x - delta, delta - y);
        spiral[y][x] = i;
        if (abs(y - delta) == abs(x - delta) or flag)
        {
            if (y >= delta and x >= delta and not flag)
            {
                flag = true;
            }
            else
            {
                flag = false;
                int temp = -dx;
                dx = dy;
                dy = temp;
            }
        }
        x += dx;
        y += dy;
    }
    return spiral;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    get_primes(99 * 99);
    assert(primes.count(3) > 0);

    while (n--)
    {
        int s;
        cin >> s;
        graph p(s, vi(s, -1));
        graph spiral = create_spiral(s);
        int maxd = 0;
        int temp = 0;
        /**
        rep(i, s)
        {
            rep(j, s)
            {
                cout << spiral[i][j] << ' ';
            }
            cout << '\n';
        }//**/
        // Left-Up to Right-Down Diagonals
        rep(k, s)
        {
            debugx("n");
            int i = 1;
            int j = k;
            temp = 0;
            while (i < s and j < s)
            {
                if (p[i][j] == -1)
                {
                    if (primes.find(spiral[i][j]) != primes.end())
                        p[i][j] = 1;
                    else
                        p[i][j] = 0;
                }
                debugx(spiral[i][j]);
                debugx(p[i][j]);
                temp += p[i][j] * spiral[i][j];
                i++;
                j++;
            }
            debugx(temp);
            maxd = max(maxd, temp);
        }

        debugx("n");
        temp = 0;
        rep(k, s)
        {
            if (p[k][k] == -1)
            {
                if (primes.find(spiral[k][k]) != primes.end())
                    p[k][k] = 1;
                else
                    p[k][k] = 0;
            }
            debugx(spiral[k][k]);
            debugx(p[k][k]);
            temp += p[k][k] * spiral[k][k];
        }
        debugx(temp);
        maxd = max(maxd, temp);

        rep(k, s - 1)
        {
            debugx("n");
            int i = k + 1;
            int j = 0;
            temp = 0;
            while (i < s and j < s)
            {
                if (p[i][j] == -1)
                {
                    if (primes.find(spiral[i][j]) != primes.end())
                        p[i][j] = 1;
                    else
                        p[i][j] = 0;
                }
                debugx(spiral[i][j]);
                debugx(p[i][j]);
                temp += p[i][j] * spiral[i][j];
                i++;
                j++;
            }
            debugx(temp);
            maxd = max(maxd, temp);
        }

        //Left-Down to Right-Up Diagonals
        repx(k, 1, s)
        {
            debugx("n");
            int i = s - 1;
            int j = k;
            temp = 0;
            while (i >= 0 and j < s)
            {
                if (p[i][j] == -1)
                {
                    if (primes.find(spiral[i][j]) != primes.end())
                        p[i][j] = 1;
                    else
                        p[i][j] = 0;
                }
                debugx(spiral[i][j]);
                debugx(p[i][j]);
                temp += p[i][j] * spiral[i][j];
                i--;
                j++;
            }
            debugx(temp);
            maxd = max(maxd, temp);
        }

        debugx("n");
        temp = 0;
        rep(k, s)
        {
            if (p[k][s - k - 1] == -1)
            {
                if (primes.find(spiral[k][s - k - 1]) != primes.end())
                    p[k][s - k - 1] = 1;
                else
                    p[k][s - k - 1] = 0;
            }
            debugx(spiral[k][s - k - 1]);
            debugx(p[k][s - k - 1]);
            temp += p[k][s - k - 1] * spiral[k][s - k - 1];
        }
        debugx(temp);
        maxd = max(maxd, temp);

        rep(k, s - 1)
        {
            debugx("n");
            int i = k + 1;
            int j = s - 1;
            temp = 0;
            while (i < s and j >= 0)
            {
                if (p[i][j] == -1)
                {
                    if (primes.find(spiral[i][j]) != primes.end())
                        p[i][j] = 1;
                    else
                        p[i][j] = 0;
                }
                debugx(spiral[i][j]);
                debugx(p[i][j]);
                temp += p[i][j] * spiral[i][j];
                i++;
                j--;
            }
            debugx(temp);
            maxd = max(maxd, temp);
        }
        cout << maxd << '\n';
    }

    return 0;
}
