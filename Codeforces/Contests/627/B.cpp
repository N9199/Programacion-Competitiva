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

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

int main()
{
    int t;
    cin >> t;
    int n;
    vi a;
    graph left;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        left.assign(n, vi(n));
        rep(i, n)
        {
            cin >> a[i];
            a[i]--;
        }
        left[0][a[0]] = 1;
        repx(i, 1, n)
            rep(j, n)
                left[i][j] = left[i - 1][j] + (a[i] == j);

        bool flag = true;
        repx(i, 1, n - 1)
        {
            if (!flag)
                break;
            rep(j, n) if (left[n - 1][j] - left[i][j] > 0 and left[i - 1][j] > 0)
            {
                cout << "YES\n";
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "NO\n";

    }
}