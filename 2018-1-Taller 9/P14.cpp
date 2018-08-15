#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> par;
typedef pair<int, ll> ilpar;
typedef vector<par> vp;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, a, b) for (int i = a; i < b; ++i)
#define invrep(i, a, b) for (int i = b; i-- > a;)
#define uset unordered_set
#define gcd __gcd
#define eb emplace_back
#define pb push_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugx(x) cerr << #x << ": " << x << endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl

int total;

vi primes;
vi numbers;
int n_primes;

void prgen()
{
    repx(i, 2, total)
    {
        if (numbers[i] == 0)
        {
            numbers[i] = i;
            ll C = 1ll * i * i;
            while (C <= total - 1)
            {
                if (numbers[C] == 0)
                    numbers[C] = i;
                C += i;
            }
            primes.eb(i);
            n_primes++;
        }
    }
}

bool in(ll n)
{
    int start = 0;
    int end = primes.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (primes[mid] == n)
            return true;
        if (primes[mid] > n)
            end = mid-1;
        else
            start = mid+1;
    }
    return false;
}

bool is_prime(int n)
{
    if (in(n))
        return true;
    for (auto p : primes)
    {
        if (n % p == 0)
            return false;
    }
    return true;
}


int main()
{
    int n;
    while (cin >> n)
    {
        total = sqrt(n) + 1;
        numbers.assign(total, 0);
        prgen();
        sort(primes.begin(), primes.end());

        invrep(i, max(n - 290, 2), n + 1)
        {
            debugx(i);
            if (is_prime(i))
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}