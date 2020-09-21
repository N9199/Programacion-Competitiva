#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef unsigned long long ull;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ull> p(20);
    p[0] = 1;
    repx(i, 1, 20) { p[i] = 10ll * p[i - 1]; }
    ll n, s, temp, temp_s, ans;
    int i;
    rep(_, t)
    {
        cin >> n >> s;
        temp_s = 0;
        temp = n;
        while (temp > 0)
        {
            temp_s += temp % 10;
            temp /= 10;
        }
        ans = 0;
        temp = n;
        i = 0;
        while (temp_s > s){
                //debugx(temp);
                //debugx(temp_s);
                assert(i < 20);
                if (temp % 10 == 0)
                {
                    i += 1;
                    temp /= 10;
                    continue;
                }
                if (temp % 10 == 9)
                {
                    ans += p[i];
                    while (temp % 10 == 9)
                    {
                        i += 1;
                        temp_s -= 9;
                        temp /= 10;
                    }
                    temp += 1;
                    temp_s += 1;
                }
                else
                {
                    ans += (10 - (temp % 10)) * p[i];
                    temp_s -= (temp % 10) - 1;
                    temp /= 10;
                    i += 1;
                    if (temp % 10 == 9)
                    {
                        //debugx(temp);
                        while (temp % 10 == 9)
                        {
                            i += 1;
                            temp_s -= 9;
                            temp /= 10;
                        }
                    }
                    temp += 1;
                }
            }
        cout << ans << '\n';
    }
}