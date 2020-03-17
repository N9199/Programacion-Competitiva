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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi b(n);
        rep(i, n) cin >> b[i];
        set<int> used;
        rep(i, n) used.emplace(b[i]);
        set<int> not_used;
        rep(i, 2 * n) if (used.find(i + 1) == used.end()) not_used.emplace(i + 1);
        vi a(2 * n);
        bool flag = true;
        rep(i, n)
        {
            int temp = *not_used.upper_bound(b[i]);
            a[2 * i] = min(temp, b[i]);
            a[2 * i + 1] = max(temp, b[i]);
            if (a[2 * i] != b[i])
            {
                cout << -1 << '\n';
                flag = false;
                break;
            }
            not_used.erase(temp);
        }
        if (flag)
        {
            rep(i, n)
            {
                if (i > 0)
                    cout << ' ';
                cout << a[2 * i] << ' ' << a[2 * i + 1];
            }
            cout << '\n';
        }
    }
}