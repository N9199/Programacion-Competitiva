#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;
typedef vector<vii> wgraph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl
#define debugm(m)             \
    cerr << #m << ":\n";      \
    for (auto &v : m)         \
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

int inline op(int a, int b) { return (a + b) % 100; }
int inline cost(int a, int b) { return a * b; }

vector<vector<ll>> DP;
vector<vector<int>> A;

// Minimize on [i,j]
ll func(int i, int j)
{
    //debugx(make_pair(i, j));
    if (DP[i][j] != -1)
        return DP[i][j];
    ll ans = 1e9;
    ll temp;
    repx(k, i, j)
    {
        temp = cost(A[i][k], A[k + 1][j]) + func(i, k) + func(k + 1, j);
        ans = min(ans, temp);
    }

    return DP[i][j] = ans;
}
void inline fill() { rep(i, A.size()) repx(j, i + 1, A.size()) A[i][j] = op(A[i][j - 1], A[j][j]); }

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        DP.assign(n, vector<ll>(n, -1));
        A.assign(n, vector<int>(n, 0));
        rep(i, n) cin >> A[i][i];
        rep(i, DP.size()) DP[i][i] = 0;
        fill();
        //debugm(A);
        cout << func(0, n - 1) << '\n';
        //debugm(DP);
    }
    return 0;
}
