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

#define debugx(x) //cerr << #x << ": " << x << endl

#define debugv(v) //        \
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
int n;
const int MOD = 37;
typedef graph matrix;

vi mult(matrix &A, vector<int> &v)
{
    vector<int> out(n);
    rep(i, n) rep(j, n)
    {
        out[i] += A[i][j] * v[j];
        out[i] %= MOD;
    }
    return out;
}

char int_to_char(int i)
{
    if (i < 26)
        return 'A' + i;
    if (i == 36)
        return ' ';
    return '0' + i - 26;
}

int main()
{
    unordered_map<char, int> c_to_i;
    rep(i, 37) c_to_i[int_to_char(i)] = i;
    cin >> n;
    //debugx(n);
    matrix a(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    string s;
    cin.ignore(10, '\n');
    getline(cin, s);
    debugx(s.size() % n);
    debugx(s.size());
    debugx((n - s.size() % n) % n);
    vi out(s.size() + (n - s.size() % n) % n);
    debugx(out.size() % n);
    debugx(out.size());
    vi in(out.size());
    rep(i, out.size())
    {
        if (i >= s.size())
            in[i] = 36;
        else
            in[i] = c_to_i[s[i]];
    }
    //debugx(s.size());
    //debugx(out.size());
    vi temp(n);
    rep(i, in.size())
    {
        if (i % n == 0 and i >= n)
        {
            temp = mult(a, temp);
            rep(j, n) out[i - n + j] = temp[j];
        }
        temp[i % n] = in[i];
    }
    debugv(in);
    debugv(temp);
    temp = mult(a, temp);
    rep(j, n) out[out.size() - n + j] = temp[j];
    debugv(out);
    rep(i, out.size()) cout << int_to_char(out[i]);
    cout << '\n';
}