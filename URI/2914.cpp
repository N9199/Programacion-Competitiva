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
#define debugv(v)  //        \
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

vector<int> primes;
//Criba
void sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);
}

template <typename _Ty1, typename _Ty2>
std::ostream &operator<<(std::ostream &_os, const std::pair<_Ty1, _Ty2> &_p)
{
    _os << _p.first << ' ' << _p.second;
    return _os;
}

struct FenwickTree
{
    vector<bool> div;
    vector<int> FT;
    int n;
    FenwickTree(int N) : n(N + 1)
    {
        FT.assign(N + 1, 0);
        div.assign(N + 1, false);
        sieve(N + 2);
    }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j)
    {
        return (query(j) - query(i - 1));
    }

    void update(int i, int v)
    {
        int s = query(i, i);
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v - s; //Set to v;
    }

    void update(ll k)
    {
        auto it = primes.rbegin();
        int j = 0;
        while (it != primes.rend() and *it > k)
        {
            for (int i = (*it); i <= n; i += (*it))
            {
                if (not div[i])
                {
                    update(i, 1);
                    div[i] = true;
                }
            }
            it++;
            j++;
        }
        primes.erase(primes.begin() + (primes.size() - j), primes.end());
    }
};

int inline par2int(const par &a)
{
    return a.first * (int)1e5 + a.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    int n, k;
    int n_max;
    umap<int, par> queries;
    umap<int, int> out;
    auto comp = [](par &a, par &b) -> bool {
        return a.second > b.second;
    };

    vp s;

    rep(i, q)
    {
        cin >> n >> k;
        queries[i] = {n, k};
        s.eb(n, k);
        n_max = max(n, n_max);
    }
    sort(s.begin(), s.end(), comp);
    FenwickTree st(n_max + 2); //Fenwick Tree
    for (auto &query : s)
    {
        //Responder queries
        st.update(query.second);
        out[par2int(query)] = (query.first - 2 + 1) - st.query(2, query.first);
    }
    rep(i, q)
    {
        cout << out[par2int(queries[i])] << '\n';
    }
}