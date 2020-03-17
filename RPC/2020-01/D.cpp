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
#define ff first
#define ss second

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
    int n, p;
    cin >> n >> p;
    map<string, int> S;
    int count = 0;
    vi m(n);
    map<int, int> special;
    rep(i, n - 1)
    {
        string s;
        cin >> s;
        if (S.find(s) == S.end())
            S[s] = count++;
        m[i] = S[s];
        if (s.substr(0, 7) == "SPECIAL")
        {
            special[S[s]] = i;
        }
    }
    int c;
    cin >> c;
    vector<pair<int, int>> X(c);
    vector<int> pos(p, -1);
    int turn = 0;
    int index = 0;
    rep(i, c)
    {
        int a;
        string s;
        cin >> a >> s;
        X[i] = {a, S[s]};
    }
    do
    {
        auto x = X[index];
        if (x.ff == 3)
        {
            pos[turn] = special[x.ss];
            continue;
        }
        else if (x.ff == 2)
        {
            for (pos[turn]++; pos[turn] < n - 1; pos[turn]++)
            {
                if (m[pos[turn]] == x.ss)
                    break;
            }
        }
        for (pos[turn]++; pos[turn] < n - 1; pos[turn]++)
        {
            if (m[pos[turn]] == x.ss)
                break;
        }
        if (pos[turn] >= n - 1)
        {
            cout << turn + 1 << '\n';
            return 0;
        }
    } while (index = (index + 1) % c, turn = (turn + 1) % p, true);
}