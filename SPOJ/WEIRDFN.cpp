#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  //cerr << #x << ": " << x << endl
#define debugv(v)  //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //\
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int main()
{
    int MOD = 1e7 + 7;
    int T;
    cin >> T;
    int a, b, c, n;
    while (cin >> a >> b >> c >> n)
    {
        vi F(n);
        F[0] = 1;
        int sum = F[0];
        priority_queue<int, vi, less<int>> maxheap;
        priority_queue<int, vi, greater<int>> minheap;
        maxheap.emplace(1);
        repx(i, 1, n)
        {
            F[i] = (a * maxheap.top() + b * (i + 1) + c) % MOD;
            sum += F[i];
            if (minheap.size() == 0)
            {
                minheap.emplace(F[i]);
                continue;
            }
            if (minheap.size() < maxheap.size())
            {
                if (F[i] < maxheap.top())
                {
                    maxheap.emplace(minheap.top());
                    minheap.pop();
                    minheap.emplace(F[i]);
                }
                else
                {
                    minheap.emplace(F[i]);
                }
            }
            else
            {
                if (F[i] <= minheap.top())
                {
                    maxheap.emplace(F[i]);
                }
                else
                {
                    maxheap.emplace(minheap.top());
                    minheap.pop();
                    minheap.emplace(F[i]);
                }
            }
            debugx(F[i]);
            debugx(maxheap.top());
            debugx(minheap.top());
            debugx((int)maxheap.size() - (int)minheap.size());
            // assert(maxheap.top() <= minheap.top());
            // assert(maxheap.size() == minheap.size() or maxheap.size() == minheap.size() + 1);
        }
        cout << sum << '\n';
    }
}