#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

struct S
{
    int id, w;
    S(int id, int w) : id(id), w(w) {}
    bool operator>(const S &s) const
    {
        return w > s.w or (w == s.w and id < s.id);
    }
};

string s;
vector<int> c(26, 0);

int main()
{
    cin >> s;

    for (char ch : s) c[ch - 'a']++;

    vector<S> v;
    rep(i, 26) v.emplace_back(i, c[i]);

    sort(v.begin(), v.end(), greater<S>());

    rep(i, 26)
    {
        if (v[i].w)
        {
            rep(j, v[i].w) cout << char(v[i].id + 'a');
        }
        else
            break;
    }

    cout << '\n';
}