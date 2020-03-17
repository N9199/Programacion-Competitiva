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

struct RMaxQ
{
    static ll op(ll x, ll y) { return max(x, y); }
};

struct RMinQ
{
    static ll op(ll x, ll y) { return min(x, y); }
};

template <class t>
class ST
{
    template <class T>
    struct node
    {
        int size;
        ll value;
        node *Left = nullptr, *Right = nullptr;
        node(int n) : size(n) {}
        // Query on range [l,r]
        ll query(int l, int r)
        {
            if (l == 0 and r == size - 1)
                return value;
            else if (r < size / 2)
                return Left->query(l, r);
            else if (l >= size / 2)
                return Right->query(l - size / 2, r - size / 2);
            else
                return T::op(Left->query(l, size / 2 - 1), Right->query(0, r - size / 2));
        }
        // Update on range [l,r]
        void update(int l, int r, ll val)
        {
            if (l == r)
            {
                value = val;
            }
            else if (r < size / 2)
            {
                node<t> *temp = new node(size / 2);
                temp->Left = Left->Left;
                temp->Right = Left->Right;
                Left = temp;
                Left->update(l, r, val);
                value = T::op(Left->value, Right->value);
            }
            else if (l >= size / 2)
            {
                node<t> *temp = new node(size - size / 2);
                temp->Left = Right->Left;
                temp->Right = Right->Right;
                Right = temp;
                Right->update(l - size / 2, r - size / 2, val);
                value = T::op(Left->value, Right->value);
            }
            else
            {
                node<t> *temp;
                temp = new node(size / 2);
                temp->Left = Left->Left;
                temp->Right = Left->Right;
                Left = temp;
                Left->update(l, size / 2 - 1, val);
                temp = new node(size - size / 2);
                temp->Left = Right->Left;
                temp->Right = Right->Right;
                Right = temp;
                Right->update(0, r - size / 2, val);
                value = T::op(Left->value, Right->value);
            }
        }

        void build(vector<ll>::iterator it)
        {
            if (size == 1)
                value = *it;
            else
            {
                Left = new node(size / 2);
                Right = new node(size - size / 2);
                Left->build(it);
                Right->build(it + size / 2);
                value = T::op(Left->value, Right->value);
            }
        }
        void build()
        {
            if (size == 1)
                value = 0;
            else
            {
                Left = new node(size / 2);
                Right = new node(size - size / 2);
                Left->build();
                Right->build();
                value = 0;
            }
        }
    };
    int n;
    vector<node<t>> nodes;

public:
    int last_version = 0;
    ST(int n)
    {
        this->n = n;
        nodes.eb(n);
        nodes[0].build();
        last_version++;
    }

    ST(vector<ll> &v)
    {
        n = v.size();
        nodes.eb(n);
        nodes[0].build(v.begin());
        last_version++;
    }

    // Update on range[l,r]
    void update(int l, int r, ll val, int ver)
    {
        nodes.eb(n);
        nodes[nodes.size() - 1].Left = nodes[ver].Left;
        nodes[nodes.size() - 1].Right = nodes[ver].Right;
        nodes[nodes.size() - 1].update(l, r, val);
        last_version++;
    }

    // Query on range [l,r]
    ll query(int l, int r, int ver)
    {
        return nodes[ver].query(l, r);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ST<RMaxQ> st(a);
    int q;
    cin >> q;
    rep(_, q)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.query(l, r, st.last_version - 1) << '\n';
    }
}