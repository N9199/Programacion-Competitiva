#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> par;
typedef vector<ll> vi;
typedef vector<ll> vll;

typedef vector<vi> graph;
typedef vector<vll> vvll;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

bool charIsNum(char c)
{
    rep(i, 10)
    {
        if (c == '0' + i)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    char temp;
    string ans;
    while (cin >> temp)
    {
        if (charIsNum(temp))
            ans += temp;
    }
    int n = stoi(ans);
    n = (36000 / __gcd(n, 36000));
    cout << n  << '\n';

    return 0;
}
