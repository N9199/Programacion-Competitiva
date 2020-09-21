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
struct seg
{
    int start, end, val;
    bool operator<(const seg &o) const { return start < o.start; }
};

struct compare
{
    bool operator()(seg &a, seg &b) { return a.val < b.val; }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int trash;
    rep(_, t)
    {
        int n, k;
        cin >> n >> k;
        vi x(n);
        rep(i, n) cin >> x[i];
        rep(i, n) cin >> trash;
        sort(x.begin(), x.end());
        debugv(x);
        set<seg> s;
        priority_queue<seg, vector<seg>, compare> q;
        int ans = 0;
        auto it2 = s.begin();
        for (auto it = x.begin(); it != x.end(); it++)
        {
            auto nex1 = upper_bound(it, x.end(), *it + k);
            if (*nex1 <= *it + k)
                nex1++;
            int temp1 = nex1 - it;
            if (!s.empty())
            {
                it2 = s.begin();
                while (it2->end < it - x.begin())
                {
                    q.emplace(*it2);
                    it2++;
                }
            }
            s.insert({(int)(it - x.begin()), (int)(nex1 - x.begin()), temp1});
            if (!q.empty())
                ans = max(ans, temp1 + q.top().val);
            else
                ans = max(ans, temp1);
        }
        cout << ans << '\n';
    }
}