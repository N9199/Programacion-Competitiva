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
#define debugv(v)         \
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
    int n, p;
    cin >> n >> p;
    vi parent(n, -1);
    vi son(n, -1);
    vi diam(n, -1);
    rep(i, p)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        parent[b] = a;
        son[a] = b;
        diam[a] = d;
    }
    string sol;
    int t;
    rep(i, n)
    {
        if (son[i] != -1 and parent[i] == -1)
        {
            t++;
            int j = son[i];
            sol += to_string(i + 1) + " ";
            int localdiam = diam[i];
            while (son[j] != -1)
            {
                localdiam = min(localdiam, diam[j]);
                j = son[j];
            }
            sol += to_string(j + 1) + " " + to_string(localdiam) + "\n";
        }
    }
    sol = sol.substr(0, sol.size() - 1);
    cout << t;
    if (sol != "")
        cout << "\n"
             << sol;
}