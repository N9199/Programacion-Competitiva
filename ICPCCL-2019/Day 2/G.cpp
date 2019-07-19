#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
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

int n;
vector<vector<int>> DP;

vector<pair<int, int>> words;
vector<int> w;

vector<vector<int>> invw(26);
vector<int> inv2w;
vector<int> inv3w;

int f(int c, int i)
{
    if (DP[c][i] != -1)
        return DP[c][i];

    int total = (int)-1e9;
    if (words[i].second == c)
        total = w[i];

    if(inv2w[i] < invw[words[i].second].size())
    {
        total = max(total, f(c, invw[words[i].second][inv2w[i]]) + w[i]);
    }
    if(inv3w[i] < invw[words[i].first].size()){
        total = max(total, f(c, invw[words[i].first][inv3w[i]]));

    }
    return DP[c][i] = total;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s;
    words.assign(n, make_pair(0, 0));
    w.assign(n, 0);
    DP.assign(26, vector<int>(n, -1));
    inv2w.assign(n, 0);
    inv3w.assign(n, 0);

    rep(i, n)
    {
        cin >> s;
        words[i] = make_pair(s[0] - 'a', s[s.size() - 1] - 'a');
        w[i] = s.size();
        invw[s[0] - 'a'].eb(i);
        inv2w[i] = invw[s[s.size() - 1] - 'a'].size();
        inv3w[i] = invw[s[0] - 'a'].size();
    }

    int M = 0;
    rep(i, n)
    {
        M = max(M, f(words[i].first, i));
    }
    cout << M << '\n';
}