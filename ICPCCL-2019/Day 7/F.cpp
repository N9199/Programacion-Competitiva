#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
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
#define debugv(v) //         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> nextc(26, vi(s1.size(), -1));
    for (int i = 0; i < s1.size(); ++i)
    {
        int c = s1[i] - 'a';
        for (int k = i; k >= 0 and nextc[c][k] == -1; k--)
        {
            nextc[c][k] = i;
        }
    }
    int total = 1;
    int nextpos = 0;
    rep(i, s2.size())
    {
        int c = s2[i] - 'a';
        nextpos = nextc[c][nextpos] + 1;
        if (nextpos == 0)
        {
            total++;
            nextpos = nextc[c][0] + 1;
            if (nextpos == 0)
            {
                cout << "-1\n";
                return 0;
            }
        }
        if (nextpos == s1.size() and i < s2.size()-1)
        {
            total++;
            nextpos = 0;
        }
    }
    cout << total << '\n';
}