#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;

typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (int i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)  //\
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

vector<int> memo;

bool particular_jump(int mod, string s, int l, int caso)
{
	for (int b = 0; b < l / mod; b++)
		if (s[caso + b * mod] == 'P')
			return false;

	return true;
}

int global_jump(int mod, string s, int l)
{
	if (memo[mod] != -1)
		return memo[mod];

	for (int a = 0; a < mod; a++)
		if (particular_jump(mod, s, l, a))
			return memo[mod] = 1;

	return memo[mod] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	while (cin >> s)
	{
		int count = 0;
		int l = s.size();

		memo.assign(l, -1);
		if (l % 2 == 0)
		{
			repx(k, 1, l / 2)
			{
				count += 2 * global_jump(gcd(l, k), s, l);
			}
			count += global_jump(l / 2, s, l);
		}
		else
		{
			repx(k, 1, l / 2 + 1)
			{
				count += 2 * global_jump(gcd(l, k), s, l);
			}
		}

		cout << count << '\n';
	}

	return 0;
}