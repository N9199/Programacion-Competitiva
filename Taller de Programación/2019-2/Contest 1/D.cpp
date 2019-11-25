#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; ++i)
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

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << _p.first << ' ' << _p.second;
    return _os;
}

int main()
{
    int n = 30000;
    int maxt = 10 * 60;
    priority_queue<par, vp, greater<par>> q;
    vi mem(n + 1);
    set<int> free;
    vi temp(n);
    generate(temp.begin(), temp.end(), []() { static int i = 0;  return ++i; });
    free.insert(temp.begin(), temp.end());

    ll t = 0;
    ll last = 0;
    string s;
    char c;
    int block_n = 0;
    while (getline(cin, s))
    {
        stringstream str;
        str << s;
        str >> t;
        str >> c;
        if (last != t)
        {
            while (!q.empty() and q.top().first < t)
            {
                par a = q.top();
                q.pop();
                if (mem[a.second] < t)
                {
                    free.emplace(a.second);
                    mem[a.first] = 0;
                }
            }
        }
        if (str >> block_n)
        {
            //assert(c == '.');
            if (free.find(block_n) == free.end())
            {
                cout << "+\n";
                mem[block_n] = t + maxt - 1;
                q.emplace(t + maxt - 1, block_n);
            }
            else
                cout << "-\n";
        }
        else
        {
            q.emplace(t + maxt - 1, *free.begin());
            mem[*free.begin()] = t + maxt - 1;
            cout << *free.begin() << '\n';
            free.erase(*free.begin());
        }
        last = t;
    }
}