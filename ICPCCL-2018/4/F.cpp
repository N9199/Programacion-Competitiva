#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<char> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i,n) for(size_t i = 0; i < (size_t)n; i++)
#define repx(i,a,b) for(size_t i = a; i < (size_t)b; i++)
#define invrep(i,a,b) for(size_t i = b; i-- > (size_t)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugv(v) //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout<<endl

class UnionFind
{
  private:
    vi p, rank, setSize, setSum;
    int numSets;
    ll sum, size;

  public:
    UnionFind(int N, ll s)
    {
        setSize.assign(N, 1);
        setSum.assign(N, 0);
        numSets = N;
        sum = 0;
        size = s;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j, ll w)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            sum += 0;
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
    ll ans() { return sum; }
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    return 0;
}
