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

struct am
{
    int zeroes, ones, others;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    rep(_, t)
    {
        cin >> n >> k;
        char c;
        bool flag = false;
        vi s(n);
        graph accum(n + 1, vi(3));
        rep(i, n)
        {
            cin >> c;
            s[i] = c - '0';
            s[i] = min(2, s[i]);
            if (i > 0)
                rep(j, 3) accum[i+1][j] += accum[i][j];
            accum[i+1][s[i]]++;
        }
        queue<am> q;
        am curr = {0, 0, 0};
        repx(i, k + 1, n + 1)
        {
            if (!q.empty() and curr.zeroes + curr.ones == 0)
            {
                curr.ones += q.front().ones;
                curr.zeroes += q.front().zeroes;
                curr.others += q.front().others;
                q.pop();
            }
            debugx(par(curr.zeroes, curr.ones));
            debugx(accum[i][0] - accum[i - k - 1][0]);
            debugx(accum[i][1] - accum[i - k - 1][1]);
            if (accum[i][1] - accum[i - k - 1][1] + curr.ones != accum[i][0] - accum[i - k - 1][0] + curr.zeroes)
            {
                if (accum[i][2] - accum[i - k - 1][2] - curr.others < abs(accum[i][1] - accum[i - k - 1][1] + curr.ones - (accum[i][0] - accum[i - k - 1][0] + curr.zeroes)))
                {
                    flag = true;
                    break;
                }
                else
                {
                    if (accum[i][1] - accum[i - k - 1][1] + curr.ones > accum[i][0] - accum[i - k - 1][0] + curr.zeroes)
                    {
                        q.push({0, accum[i][1] - accum[i - k - 1][1] + curr.ones - (accum[i][0] - accum[i - k - 1][0] + curr.zeroes), accum[i][1] - accum[i - k - 1][1] + curr.ones - (accum[i][0] - accum[i - k - 1][0] + curr.zeroes)});
                    }
                    else
                    {
                        q.push({-(accum[i][1] - accum[i - k - 1][1] + curr.ones - (accum[i][0] - accum[i - k - 1][0] + curr.zeroes)), 0, -(accum[i][1] - accum[i - k - 1][1] + curr.ones - (accum[i][0] - accum[i - k - 1][0] + curr.zeroes))});
                    }
                }
            }
            if (s[i - k - 1] == 2)
            {
                if (curr.others)
                    curr.others--;
                if (curr.zeroes)
                    curr.zeroes--;
                if (curr.ones)
                    curr.ones--;
            }
        }
        if (flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        debugx("");
    }
}