#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, ll> par;
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
    os << p.first << ' ' << p.second;
    return os;
}

int main()
{
    int t;
    cin >> t;
    rep(_, t)
    {
        int p, f, cw, cs, w, s;
        cin >> p >> f >> cw >> cs >> w >> s;
        if (cs > cw)
        {
            swap(cs, cw);
            swap(s, w);
        }
        vi ap(cs + 1);
        vi af(cs + 1);
        int x = min(p / w, cw), y = 0;
        while (y <= cs and x > 0)
        {
            while (x * w + y * s > p)
                x--;
            ap[y] = max(x, 0);
            y++;
        }
        x = min(f / w, cw), y = 0;
        while (y <= cs and x > 0)
        {
            while (x * w + y * s > f)
                x--;
            af[y] = max(x, 0);
            y++;
        }
        int ans = 0;
        rep(i, cs + 1)
        {
            int temp = 0;
            if (ap[i] * w + i * s <= p and !(af[cs - i] * w + (cs - i) * s <= f))
                temp = ap[i] + i;
            if (af[cs - i] * w + (cs - i) * s <= f and !(ap[i] * w + i * s <= p))
                temp = af[cs - i] + cs - i;
            if (af[cs - i] * w + (cs - i) * s <= f and ap[i] * w + i * s <= p)
                temp = min(cw, af[cs - i] + ap[i]) + cs;
            ans = max(ans, temp);
        }
        debugv(ap);
        debugv(af);
        cout << ans << '\n';
    }
}