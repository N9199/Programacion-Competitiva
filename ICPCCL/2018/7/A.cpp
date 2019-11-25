#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<unordered_set<int>> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define invrep(i, a, b) for (size_t i = b; i-- > (size_t)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  //cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, " ")), cout << '\n'

struct trie
{
	vector<unordered_map<char, int>> nodes;
	int next;

	trie()
	{
		nodes.eb();
		next = 1;
	}

	bool build(string s)
	{
		debugx(s);
		int i = 0;
		int v = 0;
		while (i < s.size())
		{
			if (nodes[v].find(s[i]) == nodes[v].end())
			{
				nodes.eb();
				v = nodes[v][s[i]] = next;
				i++;
				next++;
			}
			else
			{
				v = nodes[v][s[i]];
				i++;
				if (i == s.size())
					return false;
			}
		}
		return true;
	}
};

int main()
{
	int a;
	cin >> a;
	rep(_, a)
	{
		debugx(_);
		int n;
		cin >> n;
		string temp;
		trie t;
		vector<string> vs(n);
		rep(i, n)
			cin >> vs[i];

		sort(vs.begin(), vs.end(), [&](string &a, string &b) {
			return a.size() > b.size();
		});
		bool flag = false;
		rep(i, n)
		{
			debugx(vs[i]);
			if (flag)
				continue;
			if (!t.build(vs[i]))
			{
				cout << "NO\n";
				flag = true;
			}
		}
		if (!flag)
			cout << "YES\n";
		debugx(_);
	}
	return 0;
}