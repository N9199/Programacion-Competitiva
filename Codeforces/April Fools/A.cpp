#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back
#define debugx(x) cerr << #x << ": " << x << endl

vi v;
int n;
bool isSorted(int i, int j)
{
    assert(i <= j);
    if (v[i] > v[j])
        return false;
    repx(k, i + 1, j + 1)
    {
        if (v[k - 1] > v[k])
            return false;
    }
    return true;
}

int max_length(int i, int j, int c)
{
    assert(j < n);
    if (isSorted(i, j))
        return (j - i + 1);
    assert(i <= j);
    int mid = (i + j + 1) / 2;
    if (j - i <= 1)
        return 1;
    return max(max_length(i, mid - 1, c + 1), max_length(mid, j, c + 1));
}

int main(int argc, char const *argv[])
{
    cin >> n;
    v.resize(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    cout << max_length(0, n - 1, 1) << '\n';
    return 0;
}
