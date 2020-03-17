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
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
    }

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

int main()
{
    int n;
    cin >> n;
    string in;
    cin >> in;
    unordered_set<char> s;
    vector<unordered_map<char, int>> accum(n + 1);
    s.insert(in.begin(), in.end());
    for (auto c : s)
        accum[0][c];
    repx(i, 1, n+1)
    {
        for (auto c : s)
            accum[i][c] = in[i - 1] == c;
        for (auto c : s)
            accum[i][c] += accum[i - 1][c];
    }
    int ans = n;
    int i = 0, j = 0;
    while (i <= j and j <= n)
    {
        bool flag = true;
        for (auto c : s)
        {
            if (accum[i][c] >= accum[j][c])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans = min(ans, j - i);
            i++;
        }
        else
            j++;
    }
    cout << ans << '\n';
}