#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

class seg_tree
{
    vi tree, arr;
    int n;

    void build(int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = arr[left] > 0 ? 1 : (arr[left] < 0 ? -1 : 0);
        }
        else
        {
            int mid = (right + left) / 2;
            build(2 * node, left, mid);
            build(2 * node + 1, mid + 1, right);
            tree[node] = tree[2 * node] * tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        //cout<<node<<" "<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
        if (r < start or l > end)
            return 1; //Neutro
        if (l <= start and end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        //cout<<start<<" "<<end<<" "<<mid<<endl;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 * p2;
    }

    void update(int node, int start, int end, int i, int val)
    {
        if (start == end)
        {
            arr[i] = val;
            tree[node] = arr[i] > 0 ? 1 : (arr[i] < 0 ? -1 : 0);
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= i and i <= mid)
            {
                update(2 * node, start, mid, i, val);
            }
            else
            {
                update(2 * node + 1, mid + 1, end, i, val);
            }
            tree[node] = tree[2 * node] * tree[2 * node + 1];
        }
    }

  public:
    seg_tree(vi &A)
    {
        arr = A;
        n = A.size();
        tree.resize(4 * n + 5);
        build(1, 0, n - 1);
    }

    int query(int l, int r)
    {
        //cout<<"Hola"<<endl;
        int temp = query(1, 0, n - 1, l, r);
        //cout<<temp<<endl;
        return temp;
    }

    void update(int i, int value)
    {
        update(1, 0, n - 1, i, value);
        //print();
    }

    void print()
    {
        cout << "Tree:\n";
        rep(i, tree.size())
        {
            cout << i << ": " << tree[i] << '\n';
        }
        cout << "Arr:\n";
        rep(i, n)
                cout
            << i << ": " << arr[i] << '\n';
    }
};

int main()
{
    map<int, char> dict;
    dict[-1] = '-';
    dict[1] = '+';
    dict[0] = '0';
    int n, k;
    while (cin >> n >> k)
    {
        vi v(n);
        rep(i, n)
                cin >>
            v[i];
        seg_tree t(v);
        //t.print();
        char d;
        int a, b;
        rep(i, k)
        {
            cin >> d >> a >> b;
            if (d == 'C')
                t.update(a - 1, b);
            else if (d == 'P')
                cout << dict[t.query(a - 1, b - 1)];
        }
        cout << "\n";
    }
    return 0;
}