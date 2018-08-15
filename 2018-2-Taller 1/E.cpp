#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugv(v)                              \
    cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
    cerr << endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

const double PI = acos(-1);

int n;
double sinangle;

double area(int a, int b)
{
    return a * b * sinangle * 0.5;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    while (cin >> n)
    {
        sinangle = sin(2 * PI / n);
        vi S(n);
        rep(i, n)
            cin >> S[i];

        sort(S.begin(), S.end());

        vi P(n);
        int j, k;
        j = 0;
        k = n - 1;
        rep(i, n)
        {
            P[j] = S[i];
            j++;
            i++;
            if(i == n)
                break;
            P[k] = S[i];
            k--;

        }
        double sum = 0;
        rep(i, n)
        {
            sum += area(P[i], P[(i + 1) % n]);
        }
        cout << sum << '\n';
    }
    return 0;
}