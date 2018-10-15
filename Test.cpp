#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
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

#define umap unordered_map

#define debugx(x) cerr << #x << ": " << x << endl

vi primes;
void sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);
}

umap<int, int> factor(int n)
{
    umap<int, int> m;
    int temp = n;
    rep(i, n)
    {
        if (primes[i] > n)
            break;
        while (n % primes[i] == 0)
        {
            m[primes[i]] += 1;
            n /= primes[i];
        }
    }
    return m;
}

int main()
{
    int n = 1e9;
    sieve(n);
    int pmax = 0;
    int start = 17297280;
    repx(i, start, n)
    {
        auto factors = factor(i);
        int temp = 1;
        for (auto e : factors)
        {
            temp *= e.second + 1;
        }
        if (temp > pmax)
        {
            debugx(i);
            debugx(temp);
        }
        pmax = max(pmax, temp);
    }
    cout << pmax << endl;

    return 0;
}