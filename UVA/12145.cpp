#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

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

template <class T>
class Pol
{
public:
    vector<T> cofs;
    int n;
    T m_cof;

public:
    Pol(vector<T> cofs) : cofs(cofs)
    {
        m_cof = cofs[0];
        int temp = 0;
        bool flag = true;
        invrep(i, 0, cofs.size())
        {
            m_cof = max(m_cof, abs(cofs[i]));
            if (cofs[i] == T(0) and flag)
                temp++;
            else
                flag = false;
        }
        temp = cofs.size() - temp;
        if (temp > 0)
            this->cofs.erase(this->cofs.begin() + temp, this->cofs.end());
        else
            this->cofs.clear();
        if (this->cofs.size() == 0)
            this->cofs.eb(0);
        this->n = this->cofs.size() - 1;
        assert(n == this->cofs.size() - 1);
    }
    Pol()
    {
        this->n = T(0);
        cofs.eb(0);
        m_cof = 0;
    }

    int deg()
    {
        return n;
    }

    bool operator==(const Pol<T> &o)
    {
        if (n != o.n)
            return false;
        rep(i, cofs.size())
        {
            if (cofs[i] != o.cofs[i])
                return false;
        }
        return true;
    }

    Pol<T> operator+(const Pol<T> &o)
    {
        vector<T> n_cofs;
        if (n > o.n)
        {
            n_cofs = cofs;
            rep(i, o.n + 1)
            {
                n_cofs[i] += o.cofs[i];
            }
        }
        else
        {
            n_cofs = o.cofs;
            rep(i, n + 1)
            {
                n_cofs[i] += cofs[i];
            }
        }
        return Pol<T>(n_cofs);
    }

    Pol<T> operator*(const T &o)
    {
        vector<T> n_cofs = cofs;
        for (auto &cof : n_cofs)
        {
            cof *= o;
        }
        return Pol<T>(n_cofs);
    }

    Pol<T> operator*(const Pol<T> &o) //Use Fast Fourier Transform when we implement it
    {
        vector<T> n_cofs(n + o.n + 1);
        rep(i, n + 1)
        {
            rep(j, o.n + 1)
            {
                n_cofs[i + j] += cofs[i] * o.cofs[j];
            }
        }
        return Pol<T>(n_cofs);
    }

    Pol<T> operator-(const Pol<T> &o)
    {
        return (*this) + Pol<T>({-1}) * o;
    }

    T operator()(T x)
    {
        T ans1 = T(0);
        T ans2 = T(0);
        T temp1 = T(1);
        T temp2 = T(1);
        for (auto cof : cofs)
        {
            ans1 += cof * temp1;
            ans2 += cof * temp2;
            ans1 %= (ll)1e9 + 7;
            ans2 %= (ll)1e9 + 9;
            temp1 *= x;
            temp2 *= x;
            temp1 %= (ll)1e9 + 7;
            temp2 %= (ll)1e9 + 9;
        }
        return max(ans1, ans2);
    }

    Pol<T> integrate()
    {
        vector<T> n_cofs(n + 2);
        repx(i, 1, n_cofs.size())
        {
            n_cofs[i] = cofs[i - 1] / T(i);
        }
        return Pol<T>(n_cofs);
    }

    T integrate(T a, T b)
    {
        Pol<T> temp = integrate();
        return temp(b) - temp(a);
    }

    void free_gcd()
    {
        T g = 0;
        for (auto c : cofs)
        {
            g = __gcd(g, c);
        }
        for (auto &c : cofs)
        {
            c /= g;
        }
    }

    vector<T> roots()
    {
        free_gcd();
        vector<T> roots;
        /* if (typeid(T) == typeid(ll) or typeid(T) == typeid(int))
        { */
        //Do rational roots theorem
        T a0 = cofs[0];
        //If the last coefficient is zero, divide by x till it's not zero
        if (a0 == T(0))
        {
            if (n == 0)
                return {T(0)};
            else
            {
                auto it = cofs.begin();
                rep(i, n)
                {
                    if (cofs[i] == T(0))
                        it++;
                }
                roots.eb(0);
                auto temp = Pol<T>(vector<T>(it, cofs.end())).roots();
                roots.insert(
                    roots.begin(), temp.begin(), temp.end());
                return roots;
            }
        }
        //Check simple case of ax+b
        if (n == 1)
        {
            debugx(cofs[0] % cofs[1]);
            debugx(abs(cofs[0] / cofs[1]));
            if (cofs[0] % cofs[1] == 0)
                return {abs(cofs[0] / cofs[1])};
            return {};
        }
        //T an = *(cofs.rbegin());
        //Check divisors
        set<T> divisors;
        repx(i, 1, min(T(floor(sqrt(abs(a0))) + 1), 1 + m_cof))
        {
            if (a0 % T(i) == 0)
            {
                divisors.emplace(abs(T(i)));
                divisors.emplace(abs(a0 / T(i)));
            }
        }
        debugv(divisors);
        //Evaluate divisors
        for (auto d : divisors)
        {
            if ((*this)(d) == T(0))
            {
                roots.eb(abs(d));
            }
        }
        debugv(roots);
        //}
        return roots;
    }

    friend ostream &operator<<(ostream &str, const Pol<T> &a);
};

ostream &operator<<(ostream &strm, const Pol<ll> &a)
{
    debugx(a.n);
    debugv(a.cofs);
    assert(a.n == a.cofs.size() - 1);
    bool flag = false;
    if (a.n == 0)
    {
        strm << a.cofs[0];
    }
    if (a.cofs[a.n] < 0)
        flag = true;
    invrep(i, 0, a.n + 1)
    {
        if (a.cofs[i] == 0)
            continue;
        if (flag)
            if (a.cofs[i] > 0)
                strm << " + ";
            else
                strm << " - ";
        else
            flag = true;

        if (i > 1)
        {
            if (abs(a.cofs[i]) != 1)
                strm << abs(a.cofs[i]);
            strm << "x^" << i;
        }
        else if (i == 1)
        {
            if (abs(a.cofs[i]) != 1)
                strm << abs(a.cofs[i]);
            strm << "x";
        }
        else
        {
            strm << abs(a.cofs[i]);
        }
    }
    return strm;
}

int find(string s, char c)
{
    rep(i, s.size())
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

ll num;
template <class T>
Pol<T> inp(string s)
{
    auto i = find(s, '=');
    if (i > -1)
    {
        string s1 = s.substr(0, i), s2 = s.substr(i + 1);
        return inp<T>(s1) - inp<T>(s2);
    }
    i = find(s, '+');
    if (i > -1)
    {
        string s1 = s.substr(0, i), s2 = s.substr(i + 1);
        return inp<T>(s1) + inp<T>(s2);
    }
    i = find(s, '*');
    if (i > -1)
    {
        string s1 = s.substr(0, i), s2 = s.substr(i + 1);
        return inp<T>(s1) * inp<T>(s2);
    }
    vector<T> cofs;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        cofs.eb((*it) - '0');
        num = max(num, ll((*it) - '0'));
    }
    debugv(cofs);
    return Pol<T>(cofs);
}

int main(int argc, char const *argv[])
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s)
    {
        num = 1;
        if (s == "=")
            return 0;
        //Parse input
        auto p = inp<ll>(s);
        debugv(p.cofs);
        debugx(p.n);
        debugx(p);
        //Check if it's the zero polynomial
        if (p == Pol<ll>())
        {
            cout << num + 1 << "+\n";
            continue;
        }
        vector<ll> temp = p.roots();
        //Filter
        vector<ll> r;
        for (auto e : temp)
        {
            if (e > num)
                r.eb(e);
        }
        //Check if there are any roots
        if (r.size() == 0)
            cout << "*\n";
        //Output roots
        rep(i, r.size())
        {
            cout << abs(r[i]);
            if (i + 1 < r.size())
                cout << ' ';
            else
                cout << '\n';
        }
        debugv(r);
    }
    return 0;
}
