//Square Subsets 895C

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define invrep(i, a, b) for (int i = b; --i >= a;)

#define eb emplace_back

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl;

const ll MOD = 1e9 + 7;
const int MAXN = 100001;

inline ll add(ll a, ll b)
{
    return (a + b) % MOD;
}

inline ll mult(ll a, ll b)
{
    return (a * b) % MOD;
}

vll pow2(MAXN);
vi isPrime = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0};
vi masks = {0, 0, 1, 2, 0, 4, 3, 8, 1, 0, 5, 16, 2, 32, 9, 6, 0, 64, 1, 128, 4, 10, 17, 256, 3, 0, 33, 2, 8, 512, 7, 1024, 1, 18, 65, 12, 0, 0, 129, 34, 5, 0, 11, 0, 16, 4, 257, 0, 2, 0, 1, 66, 32, 0, 3, 20, 9, 130, 513, 0, 6, 0, 1025, 8, 0, 36, 19, 0, 64, 258, 13};
vi repr = {0, 1, 2, 3, 1, 5, 6, 7, 2, 1, 10, 11, 3, 13, 14, 15, 1, 17, 2, 19, 5, 21, 22, 23, 6, 1, 26, 3, 7, 29, 30, 31, 2, 33, 34, 35, 1, 37, 38, 39, 10, 41, 42, 43, 11, 5, 46, 47, 3, 1, 2, 51, 13, 53, 6, 55, 14, 57, 58, 59, 15, 61, 62, 7, 1, 65, 66, 67, 17, 69, 70};

vi freq(71, 0);
vvll memo(71, vll(1 << 11, -1));

ll dp(int n, int mask)
{
    if (n > 70)
        return mask == 0;

    if (memo[n][mask] != -1)
        return memo[n][mask];

    if (freq[n] == 0 or repr[n] != n)
        return memo[n][mask] = dp(n + 1, mask);

    if (isPrime[n] && n > 35)
        return memo[n][mask] = mult(pow2[freq[n] - 1], dp(n + 1, mask));

    return memo[n][mask] = mult(pow2[freq[n] - 1], add(dp(n + 1, mask), dp(n + 1, mask ^ masks[n])));
}

void fill2pow()
{
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow2[i] = mult(pow2[i - 1], 2);
}

int main(int argc, char const *argv[])
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    scanf("%d", &n);
    rep(_, n)
    {
        int x;
        scanf("%d", &x);
        freq[repr[x]]++;
    }
    fill2pow();

    printf("%I64d\n", add(mult(pow2[freq[1]], dp(2, 0)), MOD - 1));
    return 0;
}
