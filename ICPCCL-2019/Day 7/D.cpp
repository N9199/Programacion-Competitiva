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
#define debugv(v)//         \
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
    int n;
    cin >> n;
    vp players(n);
    rep(i, n)
    {
        cin >> players[i].first;
        players[i].second = i;
    }
    sort(players.begin(), players.end());

    debugv(players);
    vp team1;
    vp team2;
    ll vteam1 = 0, vteam2 = 0;
    rep(i, n / 2)
    {
        if (vteam1 > vteam2)
        {
            team1.eb(players[2 * i]);
            team2.eb(players[2 * i + 1]);
            vteam1 += players[2 * i].first;
            vteam2 += players[2 * i + 1].first;
        }
        else
        {
            team2.eb(players[2 * i]);
            team1.eb(players[2 * i + 1]);
            vteam2 += players[2 * i].first;
            vteam1 += players[2 * i + 1].first;
        }
    }
    if (n % 2 == 1)
    {
        if (vteam1 > vteam2)
        {
            vteam2 += players[n - 1].first;
            team2.eb(players[n - 1]);
        }
        else
        {
            vteam1 += players[n - 1].first;
            team1.eb(players[n - 1]);
        }
    }
    debugv(team1);
    debugv(team2);
    cout << team1.size() << '\n';
    rep(i, team1.size())
    {
        cout << (team1[i].second + 1) << ((i == team1.size() - 1) ? "\n" : " ");
    }
    cout << team2.size() << '\n';
    rep(i, team2.size())
    {
        cout << (team2[i].second + 1) << ((i == team2.size() - 1) ? "\n" : " ");
    }
}