#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;

typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)                              \
    cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, w, max_l;
        cin >> n >> w >> max_l;
        vi wagons;
        int temp;
        int last_temp;
        cin >> temp;
        if (temp > 1)
            wagons.pb(temp - 1);
        wagons.pb(-temp);
        last_temp = temp;

        rep(_, w - 1)
        {
            cin >> temp;
            if (temp - last_temp - 1 > 0)
                wagons.pb(temp - last_temp - 1);
            wagons.pb(-temp);
            last_temp = temp;
        }
        if (n - temp > 0)
            wagons.pb(n - temp);

        int k;
        int start = 1, end = n + 1;
        int used_l = 0;
        debugv(wagons);
        debugx(max_l);
        while (start < end)
        {
            k = (start + end) / 2;
            used_l = 1;
            temp = 0;
            debugx(k);
            rep(i, wagons.size())
            {
                debugx(temp);
                debugx(used_l);
                if (wagons[i] < 0)
                {
                    if (temp + 1 == k)
                    {
                        used_l++;
                        temp = 0;
                    }
                    else
                        temp++;
                }
                else
                {
                    if (wagons[i] + temp <= k)
                        temp += wagons[i];
                    else
                    {
                        temp = wagons[i] + temp - k;
                        used_l++;
                    }
                }
            }
            if (used_l < max_l)
                start = k + 1;
            else
                end = k;
        }
        cout << k << '\n';
    }
    return 0;
}