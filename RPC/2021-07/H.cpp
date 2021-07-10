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
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)
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

int main()
{
    int n, s;
    cin >> s >> n;
    char c;
    vi a(n);
    vi b(n);
    rep(i, n)
    {
        cin >> a[i] >> c;
        if (c == 'n' and s > 1)
        {
            b[i] = a[i];
            a[i] = 0;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    debugv(a);
    debugv(b);
    int i = 0;
    while (a[++i] == 0)
        ;
    int min_t = 1;
    repx(j, i, n)
    {
        if (a[j] >= min_t)
            min_t++;
        else
        {
            cout << "No\n";
            return 0;
        }
    }
    i = 0;
    while (b[++i] == 0)
        ;
    min_t = 1;
    int cs = 0;
    repx(j, i, n)
    {
        if (b[j] >= min_t and cs < s - 1)
            cs++;
        else
        {
            cout << "No\n";
            return 0;
        }
        if (cs == s - 1 or (j > 0 and b[j] > b[j - 1]))
        {
            cs = 0;
            min_t++;
        }
    }
    cout << "Yes\n";
}