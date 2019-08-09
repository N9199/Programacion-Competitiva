#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;

typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugv(v)  //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << ' ' << e; \
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

struct employee
{
    int id, money, h;
    int boss = 0, n = 0;
    vi subordinates;
    employee(int id, int money, int h) : id(id), money(money), h(h) {}
    employee() {}

    bool operator<(const employee &o) const
    {
        return money < o.money;
    }

    friend ostream &operator<<(ostream &strm, const employee &o);
};

ostream &operator<<(ostream &strm, const employee &o)
{
    return strm << '(' << o.id << "," << o.money << "," << o.h << ')';
}

void func(unordered_map<int, employee> &q, int id)
{
    for (auto e : q[id].subordinates)
    {
        func(q, e);
        q[id].n += q[e].n + 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        int m, q;
        cin >> m >> q;
        vector<employee> v;

        rep(_, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v.eb(a, b, c);
        }

        sort(v.begin(), v.end(), [](const employee &a, const employee &b) {
            if (a.h > b.h)
                return true;
            else if (a.h == b.h and a.money > b.money)
                return true;
            return false;
        });

        set<employee> s;
        unordered_map<int, employee> queries;

        rep(i, m)
        {
            if (i != 0)
            {
                auto it = s.upper_bound(v[i]);
                v[i].boss = (*it).id;
                queries[v[i].boss].subordinates.eb(v[i].id);
            }

            queries[v[i].id] = v[i];
            s.emplace(v[i]);
        }

        func(queries, v[0].id);

        rep(_, q)
        {
            int a;
            cin >> a;
            cout << queries[a].boss << ' ' << queries[a].n << '\n';
        }
    }
    return 0;
}