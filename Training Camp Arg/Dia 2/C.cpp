#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- >= (int)a;)

#define eb emplace_back

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m) //            \
    cerr << #m << ":\n";      \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << e << " "; \
        cerr << "\n";         \
    }                         \
    cerr << endl

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << '(' << _p.first << ',' << _p.second << ')';
    return _os;
}

int main()
{
    int n, p;
    cin >> n >> p;
    vi a(n);
    char temp;
    rep(i, n)
    {
        cin >> temp;
        a[i] = temp - '0';
    }
    bool ans = true;
    int last = -1;
    rep(i, p)
    {
        last = -1;
        for (int j = i; j < n; j += p)
            if (a[j] >= 0)
            {
                if (last == -1)
                {
                    last = a[j];
                }
                else if (a[j] == last)
                    ans = false;
            }
            else if (last != -1)
                a[j] = last ^= 1;
    }
    debugv(a);
    if (ans)
    {
        invrep(i, n - p, n)
        {
            last = -1;
            for (int j = i; j >= 0; j -= p)
                if (last == -1)
                {
                    if (a[j] >= 0)
                        last = a[j];
                    else
                        a[j] = last = 0;
                }
                else
                    a[j] = last ^= 1;
        }
        rep(i, n) cout << a[i];
        cout << '\n';
    }
    else
        cout << "No\n";
}