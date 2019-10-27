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
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    int totalcolupdate = 0;
    int totalrowupdate = 0;
    vi rowvalue(n);
    vi colvalue(m);
    graph matrix(n, vi(m, 0));
    rep(i, n) rep(j, m)
    {
        cin >> matrix[i][j];
        rowvalue[i] += matrix[i][j];
        colvalue[j] += matrix[i][j];
    }
    priority_queue<ll, vi> q1;                  //Rows (n)
    priority_queue<ll, vi> q2;                  //Cols (m)
    priority_queue<ll, vi, greater<ll>> usedq2; //Used cols (m)
    rep(i, n)
    {
        q1.emplace(rowvalue[i]);
    }

    rep(i, m)
    {
        q2.emplace(colvalue[i]);
    }
    ll ans_cols = 0;
    ll ans_rows = 0;
    ll temp, temp2;
    int a = k; // b = k-a
    rep(i, k)
    {
        temp = q2.top();
        q2.pop();
        ans_cols += temp;
        q2.emplace(temp - n * p);
        usedq2.emplace(temp);
    }
    ll ans = ans_cols;
    for (a = k - 1; a >= 0; a--)
    {
        temp = usedq2.top();
        usedq2.pop();
        temp2 = q1.top();
        q1.pop();
        ans_cols += -temp;
        ans_rows += (k - a - 1) * p;
        ans_rows += temp2 - (a)*p;

        q1.emplace(temp2 - m * p);
        ans = max(ans, ans_cols + ans_rows);
    }
    cout << ans << '\n';
}
