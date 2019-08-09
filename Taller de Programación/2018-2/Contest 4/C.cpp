#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;

typedef vector<ll> vi;
typedef vector<par> vp;
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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)  //\
    cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
    cerr << endl
#define debugm(m)  //\
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int main()
{
    int n;
    cin >> n;
    vp prog;
    string s;
    getline(cin, s);
    unordered_map<char, int> in;
    in['>'] = 0;
    in['v'] = 1;
    in['<'] = 2;
    in['^'] = 3;
    vi ins(s.size());
    rep(i, s.size())
    {
        ins[i] = in[s[i]];
    }
    unordered_map<char, int> m;
    m['#'] = -2;
    m['.'] = -1;
    m['R'] = 0;
    int x, y;
    graph f(n, vi(n));
    string temp;
    rep(i, n)
    {
        getline(cin, temp);
        rep(j, n)
        {
            f[i][j] = m[temp[j]];
            if (f[i][j] == 0)
            {
                x = i;
                y = j;
                f[x][y] = -1;
            }
        }
    }
    int size = INT32_MAX;
    int i = 0;
    int diff = -1;
    int last_diff = -2;
    while (i < size)
    {
        
    }

    return 0;
}