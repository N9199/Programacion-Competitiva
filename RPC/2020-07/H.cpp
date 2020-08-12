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

#define ff first
#define ss second



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    rep(_, t)
    {
        int n;
        cin >> n;
        vi s(n);
        rep(i, n) cin >> s[i];
        debugv(s);
        graph a(n - 1, vi(n, -1));
        graph b(n - 1, vi(n, n));
        repx(i, 1, n) invrep(j, 0, i) if (s[i] > s[j])
        {
            a[0][i] = j;
            break;
        }
        invrep(i, 0, n-1) repx(j, i+1,n) if (s[i] < s[j])
        {
            b[0][i] = j;
            break;
        }
        debugm(a);
        debugm(b);
    }
}