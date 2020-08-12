#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> //Import all

using namespace std; //Less verbose code

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

// Reps are inclusive exclusive (i.e. range is [a,b))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

// Base two log for ints and for ll
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//Debugs single variables (e.g. int, string)
#define debugx(x) //cerr << #x << ": " << x << endl
//Debugs Iterables (e.g. vi, uset<int>)
#define debugv(v) //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
//Debugs Iterables of Iterables (e.g. graph, umap<int,umap<int, int>)
#define debugm(m) //          \
    cerr << #m << endl;       \
    for (auto v : m)          \
    {                         \
        for (auto e : v)      \
            cerr << " " << e; \
        cerr << endl;         \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl

//Outputs generic pairs through streams (including cerr and cout)
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

void func(string &s, int i, int j, vi &fill, vi &accum)
{
    if (s[i] == '[')
    {
        int last = i + 1;
        repx(k, i + 1, j) if (s[k] == ',')
        {
            fill[accum[last]] = stoi(s.substr(last, k - last - 1));
            last = k + 1;
        }
        fill[accum[last]] = stoi(s.substr(last, j - last - 1));
    }
    else if (s[i] == 'c')
    {
    }
    else if (s[i] == 's' and s[i + 1] == 'o')
    {
    }
    else if (s[i] == 's' and s[i + 1] == 'h')
    {
    }
}

int main()
{
    string A;
    cin >> A;
    string B;
    cin >> B;
    vi accumA(A.size());
    vi accumB(B.size());
    bool flag = false;
    rep(i, A.size())
    {
        if (i > 0)
            accumA[i] = accumA[i - 1];
        if (flag)
        {
            if (A[i] == ']')
            {
                accumA[i]++;
                flag = false;
            }
            else if (A[i] == ',')
                accumA[i]++;
        }
        else if (A[i] == '[')
            flag = true;
    }
    rep(i, B.size())
    {
        if (i > 0)
            accumB[i] = accumB[i - 1];
        if (flag)
        {
            if (B[i] == ']')
            {
                accumB[i]++;
                flag = false;
            }
            else if (B[i] == ',')
                accumA[i]++;
        }
        else if (B[i] == '[')
            flag = true;
    }
    vi ansA(*accumA.rbegin());
    vi ansB(*accumB.rbegin());
}