#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct par
{
    int first, second;

    friend ostream &operator<<(ostream &strm, const par &a);
};

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

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << ' ' << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

ostream &operator<<(ostream &strm, const par &a)
{
    return strm << '(' << a.first << ',' << a.second << ')';
}

int main()
{
    int n, t;
    cin >> n >> t;
    vp temp(n);
    rep(i, n)
    {
        cin >> temp[i].second;
    }
    rep(i, n)
    {
        cin >> temp[i].first;
    }
    sort(temp.begin(), temp.end(), [](par &a, par &b) {
        if (a.first < b.first)
            return true;
        else if (a.first == b.first and b.second < a.second)
            return true;
        return false;
    });
    debugv(temp);
    return 0;
}