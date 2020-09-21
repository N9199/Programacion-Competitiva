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
        string s;
        cin >> s;
        int x;
        cin >> x;
        int n = s.size();
        vi ans(n, -1);
        vi done(n);
        bool doable = true;
        if (n % 2 and s[n / 2] == '1')
        {
            doable = false;
            goto end;
        }
        rep(i, n) if (s[i] == '0')
        {
            if (i >= x)
                ans[i - x] = 0;
            if (i + x < n)
                ans[i + x] = 0;
        }
        rep(i, n) if (s[i] == '1')
        {
            if (i >= x and i + x < n)
            {
                if (ans[i - x] == 0 and ans[i + x] == 0)
                {
                    doable = false;
                    goto end;
                }
                else if (ans[i - x] == 0)
                    ans[i + x] = 1;
                else if (ans[i + x] == 0)
                    ans[i - x] = 1;
            }
            else if (i >= x)
            {
                if (ans[i - x] == 0)
                {
                    doable = false;
                    goto end;
                }
                else
                    ans[i - x] = 1;
            }
            else if (i + x < n)
            {
                if (ans[i + x] == 0)
                {
                    doable = false;
                    goto end;
                }
                else
                    ans[i + x] = 1;
            }
        }
        rep(i, n) if (ans[i] == -1) ans[i] = 1;

    end:
        if (doable)
        {
            rep(i, n) cout << ans[i];
            cout << '\n';
        }
        else
            cout << "-1\n";
    }
}