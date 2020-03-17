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

struct FenwickTree
{
    vector<int> FT;
    FenwickTree(int N) { FT.resize(N + 1, 0); }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j) { return query(j) - query(i - 1); }

    void update(int i, int v)
    {
        int s = query(i, i); // Sets range to v?
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v - s;
    }

    // Queries puntuales, Updates por rango
    void update(int i, int j, int v)
    {
        update(i, v);
        update(j + 1, -v);
    }
};

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vi s(n);
    vi done(n);
    priority_queue<ii> q;
    rep(i, n)
    {
        char c;
        cin >> c;
        s[i] = c - 'a';
        q.emplace(s[i], i);
    }
    FenwickTree FT(n);
    while (!q.empty())
    {
        debugv(s);
        int curr = q.top().first, curr_i = q.top().second;
        if (done[curr_i])
        {
            q.pop();
            continue;
        }
        curr_i -= FT.query(curr_i + 1);
        if ((curr_i > 0 and s[curr_i - 1] == s[curr_i] - 1) or (curr_i < s.size() - 1 and s[curr_i + 1] == s[curr_i] - 1))
        {
            FT.update(q.top().second + 1, n, -1);
            s.erase(s.begin() + curr_i);
            ans++;
            bool flag1 = true;
            bool flag2 = true;
            int count1 = 0;
            int count2 = 0;
            repx(i, 1, n)
            {
                if (flag2 and curr_i + i < s.size())
                {
                    if (s[curr_i + i] == s[curr_i])
                    {
                        count2++;
                        flag2 = true;
                    }
                    else
                        flag2 = false;
                }
                if (flag1 and curr_i - i >= 0)
                {
                    if (s[curr_i - i] == s[curr_i])
                    {
                        count1++;
                        flag1 = true;
                    }
                    else
                        flag1 = false;
                }
                if (flag1 or flag2)
                    break;
            }
            debugx(curr_i);
            debugx(count1);
            debugx(count2);
            bool flag = (curr_i + count2 < s.size() - 1 and s[curr_i + count2 + 1] == s[curr_i] - 1) or (curr_i - count1 > 0 and s[curr_i - count1 - 1] == s[curr_i] - 1);
            debugx(flag);
            if (count2 and flag)
            {
                invrep(i, 1, count2 + 1)
                    s.erase(s.begin() + i + curr_i);
                int i = 1;
                FT.update(q.top().second + 2, n, -count2);
                while (count2)
                {
                    if (!done[q.top().second])
                        count2--;
                    done[q.top().second + i] = 1;
                    i++;
                }
                ans += count2;
            }
            if (count1 and flag)
            {
                repx(i, 1, count1 + 1)
                    s.erase(s.begin() + curr_i - 1);
                int i = 1;
                FT.update(1, q.top().second, -count1);
                while (count1)
                {
                    if (!done[q.top().second])
                        count1--;
                    done[q.top().second - i] = 1;
                    i++;
                }
                ans += count1;
            }
        }
        done[q.top().second];
        q.pop();
    }
    std::cout << ans << '\n';
}