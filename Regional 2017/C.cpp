#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << ' ' << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

#define NOPE false;

int main()
{
    int k, n;
    while (cin >> k >> n)
    {
        vi numbers(++k);
        rep(_, n)
        {
            int temp;
            cin >> temp;
            numbers[temp]++;
        }
        debugv(numbers);
        int fmin = INT32_MAX, fmax = 0;
        int xmin, xmax;
        repx(i, 1, k)
        {
            if (fmin > numbers[i])
            {
                fmin = numbers[i];
                xmin = i;
            }
            if (fmax < numbers[i])
            {
                fmax = numbers[i];
                xmax = i;
            }
        }
        if (fmax - fmin > 2)
        {
            cout << "*\n";
            continue;
        }
        if (fmax - fmin == 2)
        {
            bool maybe = true;
            repx(i, 1, k)
            {
                if (i == xmin or i == xmax)
                    continue;
                if (numbers[i] != fmin + 1)
                {
                    maybe = NOPE;
                    break;
                }
            }
            if (maybe)
                cout << "-" << xmax << " +" << xmin << '\n';
            else
                cout << "*\n";
        }
        else
        {
            debugx(fmax);
            repx(i, 1, k)
            {
                if (i == xmin or i == xmax)
                    continue;
                if (numbers[i] != fmax)
                    goto second_chance;
            }
            cout << "+" << xmin << endl;
            continue;
        second_chance:
            repx(i, 1, k)
            {
                if (i == xmin or i == xmax)
                    continue;
                if (numbers[i] != fmin)
                    goto nope;
            }
            cout << "-" << xmax << endl;
            continue;
        nope:
            cout << "*\n";
        }
    }
}